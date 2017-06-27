#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int f(const int i){}

int main() { 
    const int ci{};
    int i = 0;
    const int & j = 1;
    int * const pi = &ci;
    f(i);
    return 0; 
}
