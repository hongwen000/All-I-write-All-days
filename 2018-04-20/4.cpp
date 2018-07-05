#include <omp.h>
#include <iostream>

using namespace std;

int area = 0;
int main(int argc, const char *argv[])
{
#pragma omp parallel for num_threads(20)
        for(int i = 0; i < 1000; ++i)
        {
            int t = area;
            t = t + i;
            area = t;
        }
    std::cout << area << std::endl;
    return 0;
}
