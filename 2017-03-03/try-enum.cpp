#include <iostream>
using namespace std;
enum em { e1 = 0, e2 };
int main()
{
    auto b = static_cast<em>(2);
    return 0;
}
