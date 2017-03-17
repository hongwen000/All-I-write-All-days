// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
//快速排序算法 ver 1.0 大锐手敲
#include <iostream>
using namespace std;
#define MAXSIZE 1024
typedef struct
{
	int r[MAXSIZE + 1];
	int Length;
}SqList;
void swap(SqList *L, int i, int j)
{
	int temp;
	temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
int GetCenter(SqList *L, int low, int high)
{
	int Center;
	Center = L->r[low];
	while (low < high)
	{
		while (low < high && L->r[high] >= Center)
			high--;
		swap(L, low, high);
		while (low < high&&L->r[low] <= Center)
			low++;
		swap(L, low, high);
	}
	return low;
}
void Qsort(SqList *L, int low, int high)
{
	int Center;
	if (low < high)
	{
		Center = GetCenter(L, low, high);
		Qsort(L, low, Center - 1);
		Qsort(L, Center + 1, high);
	}

}
void QuickSort(SqList *L)
{
	Qsort(L, 1, L->Length);
}


int main()
{
	
	SqList L;
	SqList *List;
	List = &L;
	List->Length = 3;
	int i = 3;
	while (i > 0)
	{
		cin >> List->r[i];
		i--;
	}
	QuickSort(List);
	i = 1;
	
	cout << List->r[1]<< ' ';
	cout << List->r[2]<< ' ';
	cout << List->r[3]<<endl;

	i++;

	return 0;
}
