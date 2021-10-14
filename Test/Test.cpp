// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int arr_size = 100;

void num_file()
{
	ofstream out;

	out.open("numbers1.txt");
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			out << 1 + rand() % 10 << " ";
		}
		out << endl;
	}
	out.close();

	out.open("numbers2.txt");
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			out << 1 + rand() % 10 << " ";
		}
		out << endl;
	}
	out.close();
}

int main()
{
	//srand(time(0));
	num_file();

	vector<vector<long>> arr1(arr_size, vector<long>(arr_size));
	vector<vector<long>> arr2(arr_size, vector<long>(arr_size));

	unsigned int start_time = clock();

	// Считаем матрицу из файла
	ifstream in("numbers1.txt");
	for (long long i = 0; i < arr_size; i++)
		for (long long j = 0; j < arr_size; j++)
			in >> arr1[i][j];
	in.close();

	in.open("numbers2.txt");
	for (long long i = 0; i < arr_size; i++)
		for (long long j = 0; j < arr_size; j++)
			in >> arr2[i][j];
	in.close();

	// Евклидова норма матрицы
	long double S = 0;
	for (int i = 0; i < arr_size; ++i) 
	{
		for (int j = 0; j < arr_size; ++j) 
		{
			S += arr1[i][j] * arr1[i][j];
		}
	}
	S = sqrt(S);
	//cout << S << endl << endl;

	vector<vector<long>> arr3(arr_size, vector<long>(arr_size));

	for (int i = 0; i < arr_size; ++i)
	{
		for (int j = 0; j < arr_size; ++j)
		{
			arr3[i][j] = S * arr1[i][j] + arr2[i][j] - arr1[i][j];
		}
	}

	ofstream out("out.txt");
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			out << arr3[i][j] << " ";
		}
		out << endl;
	}

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << search_time/1000;
}