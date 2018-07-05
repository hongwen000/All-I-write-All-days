#include <omp.h>
#include <iostream>
int main(int argc, const char *argv[])
{
    std::cout << omp_get_max_threads() << std::endl;
    return 0;
}
