#include <iostream>
using namespace std;
typedef struct  __attribute__((packed))
{
    char c;
    double d;
    short s;
    int i;
} Foo;

struct Foo2
{
    char c;
    short s;
    int i;
    double d;
};

int main()
{
    cout << sizeof(Foo) << endl;
    cout << sizeof(Foo2) << endl;
}