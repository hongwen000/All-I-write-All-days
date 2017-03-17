// 10 method of initialing Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	const int ARRAY_SIZE = 3;
	int Array[ARRAY_SIZE];
	cout << "Initialing Method 1 " << endl;
	cout << "Please input"<<ARRAY_SIZE<<" numbers" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cin >> Array[i];
	}
	//cout << "Initialing Method 2" << endl;
	//for (int i = 0; i < ARRAY_SIZE; i++)
	//{
	//	Array[i] = rand() % 100;
	//}
	cout << "Printing" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << Array[i] << endl;
	}
	int _Array[ARRAY_SIZE];
	cout << "Copying" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		_Array[i] = Array[i];
	}
	cout << "Summing Up" << endl;
	int sum=0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		sum += Array[i];
	}
	cout << sum << endl;
	cout << "Looking for the largest " << endl;
	int Largest = Array[0];
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (Array[i] > Largest)
		{
			Largest = Array[i];
		}
	}
	cout << Largest << endl;
	cout << "Shuffling" << endl;
	srand(time(0));
	for (int i = ARRAY_SIZE - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int temp = Array[i];
		Array[i] = Array[j];
		Array[j] = temp;
	}
	cout << "Printing" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << Array[i] << endl;
	}
    return 0;
}

