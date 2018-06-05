#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;
string dx;
void print() {
    cout << dx;
}
void(*syscall[256])(void);
int main() {
    dx = "hello world";
    syscall[1] = print;
    syscall[1]();
}
