#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));
    int cases = 10;
    std::cout << cases << std::endl;
    while(cases--) {
        int lw = rand() % 10;
        int lt = rand() % 1000000;
        while(lw--)
            std::cout << (char)(rand() % 26 + 65);
        std::cout << endl;
        while(lt--)
            std::cout << (char)(rand() % 26 + 65);
        std::cout << endl;
    }
}

