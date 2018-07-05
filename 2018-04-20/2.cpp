#include <omp.h>
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int numt = omp_get_num_threads();
#pragma omp parallel shared(numt)
    {
        int tid = omp_get_thread_num();
        printf("hi, from %d\n", tid);
#pragma omp barrier
        if(tid == 0)
            printf("%d threads say hi!\n", numt);
    }
    return 0;
}
