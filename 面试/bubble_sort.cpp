#include <climits>
#include <algorithm>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;
#define LEN 10000
int arr1[LEN];
int arr2[LEN];

void bubble_sort(int *arr, int n)
{
    // 仅仅是用来控制轮数的
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    srand(time(0));
    while(true)
    {
        int n = rand() % LEN;
        for(int i = 0; i < n; ++i)
        {
            arr1[i] = (rand() % 2 ? 1 : -1) * rand() % INT_MAX;
            arr2[i] = arr1[i];
        }
        std::sort(arr1, arr1+n);
        bubble_sort(arr2, n);
        for(int i = 0; i < n; ++i)
        {
            if(arr1[i] != arr2[i])
            {
                cout << "Wrong!" << endl;
                for(int i = 0; i < n; ++i)
                {
                    cout << arr1[i] << " ";
                }
                cout << endl;
                for(int i = 0; i < n; ++i)
                {
                    cout << arr2[i] << " ";
                }
                cout << endl;
                exit(1);
            }
        }
        cout << "OK" << endl;
    }
}