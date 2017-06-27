#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const double c1_k2  = 6E-34;
const double c1_k3  = 8E-12;
const double Co2    = 0.21;
 
double calc_k2(double T) {
    return c1_k2 * pow((T / 300.0), -2.4);
}

double calc_k4(double T) {
    return pow(c1_k3, (-2060.0 / T));
}

double calc_ans(double k3, double k2, double Na) {
    return (k3 / (k2 * Co2 * Na * Na));
}

int main()
{
    double T, k3, Na;
    int n = 0;
    cout << "请依次输入T, k3, Na, 用空格分隔" << endl;
    cout << "支持科学记数法,例如 1.4E18 是有效输入" << endl;
    cout << "按Ctrl + C 结束程序" << endl;
    cout << "请输入> ";
    while (cin  >> T >> k3 >> Na) {
        cout << endl << "------------------------------------" << endl;
        cout << "当前是第一组运算"<< endl;
        double k2 = calc_k2(T);
        cout << "k2 = " << k2 << endl;
        double k4 = calc_k4(T);
        cout << "k4 = " << k4 << endl;
        cout << "结果为 " << calc_ans(k3, k2, Na) << endl;
    }
    return 0;
}

