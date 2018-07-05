#include <omp.h>
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    int nthreads, tid;
    cout.sync_with_stdio(false);
#pragma omp parallel private (nthreads, tid)
    {
        tid = omp_get_thread_num();
        if(tid == 0)
        {
            nthreads = omp_get_num_threads();
            fprintf(stderr, "Number of threads = %d\n", nthreads);
        }
            fprintf(stderr, "Hello World from thread = %d\n", tid);
    }
int n = 100;
int a[1000], b[1000], s[1000];
#pragma omp parallel for
    for(int i = 0; i < n; ++i)
        a[i] = 1;
#pragma omp parallel for
    for(int i = 0; i < 1000; ++i)
        b[i] = 1;
#pragma omp parallel for
    for(int i = 0; i < 1000; ++i)
        s[i] = a[i] + b[i];
    int x;
#pragma omp parallel for lastprivate(x)
    for(int i = 0; i < 100; i++)
        x = i;
    std::cout << x << std::endl;
    return 0;
}
