#include <iostream>
using namespace std;
int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int sum = 0;
        int input = 0;
        int result = 0;
        cin >> input;
        while(input != -1) {
            result += input;
            cin >> input;
        }
        cout << result << endl;
    }
    return 0;
}
