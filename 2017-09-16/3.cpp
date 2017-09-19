#include <iomanip>
#include <iostream>
using namespace std;
#define PI 3.14
int main()
{
    double r, h;
    cin >> r >> h;
    cout << fixed << setprecision(2) << PI * r * r << endl << PI * r * r * h << endl << PI * 4.0 / 3.0 * r * r * r << endl;
}
