#include <atomic>
#include <iostream>
using namespace std;
int main()
{
    std::atomic_bool flag;
    std::cout << flag.is_lock_free() << std::endl;
}
