#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() { 
    int a[3][4] = {1,5,8,10,11,3,4,8,7};
    int *p = (int*) a;
    int (*q)[4] = a;
    p += 1;
    q += 1;
    cout << *q + 3 -p << endl;
    return 0; 
}
