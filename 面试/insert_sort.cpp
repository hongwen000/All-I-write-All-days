#include <climits>
#include <algorithm>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;
#define LEN 20000
int arr1[LEN];
int arr2[LEN];
void insert_sort(int* arr, int n)
{
    for(int i = 1; i < n; ++i)
    {
        int tmp = arr[i];
        int m = i - 1;
        for(; m >=0; --m)
        {
            if(tmp < arr[m])
                arr[m+1] = arr[m];
            else
                break;
        }
        arr[m+1] = tmp;
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
        insert_sort(arr2, n);
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
                exit(1);
            }
        }
        cout << "OK" << endl;
    }
}