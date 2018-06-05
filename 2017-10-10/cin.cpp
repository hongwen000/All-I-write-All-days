#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main() {
//    std::stringstream s;
//    while(s.get()) {
    std::string s;
    while(std::getline(std::cin, s)){
        cout << ">>>" << endl;
        if(s == "exit") {
            return 0;
        }
    }
}
