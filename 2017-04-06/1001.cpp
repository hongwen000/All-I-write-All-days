#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int b[2] = { 0, 1 };
    int *a = b;
    cout << *a++ << endl;
    return 0;
}
