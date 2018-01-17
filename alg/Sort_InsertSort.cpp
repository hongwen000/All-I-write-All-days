#include <iostream>
#include <algorithm>
using namespace std;
int* insertSort(int* seq, int n)
{
    if(n == 1 || n == 0) return seq;
    for(int i = 2; i < n; ++i) 
    {
        int temp = seq[i];
        for(int j = i; j > 1; --j)
        {
            if(seq[j] > temp)
                seq[j] = seq[j - 1];
        }
        seq[i] = temp;
    }
    return seq;
}
