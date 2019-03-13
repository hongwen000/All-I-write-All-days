#include <stdint.h>

void select_sort(int *arr, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        int m = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[m])
            {
                m = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[m];
        arr[m] = tmp;
    }
}