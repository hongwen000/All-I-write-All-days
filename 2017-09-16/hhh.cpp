#include <iostream>
using namespace std;
struct tag_1{};
struct tag_2{};
void f(string s, tag_1) {
    cout << "f(string s) is called" << endl;
}
void f(const char* s, tag_2) {
    cout << "f(const char* s) is called" << endl;
}
int main() 
{
    f("hhh", tag_1());
}
