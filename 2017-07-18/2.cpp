#include <string>
#include <iostream>
using namespace std;
int main()
{
    while(1)
    {
        string command;
        getline(cin, command);
        cout << command.substr(0, command.find(" ")) << endl;
        cout << command.substr(command.find(" ") + 1) << endl;
    }
}


