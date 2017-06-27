#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

const double T1 = 273.16;
const double esp = 0.1;
const double delta = 0.5;

double calcLogeW(double T)
{
    double term1 = 10.79574 * (1 - T1 / T);
    cout << "term 1 = " << term1 << endl;
    double term2 = 5.02800 * log10(T / T1);
    cout << "term 2 = " << term2 << "log~ = " << log10(T / T1) << endl;
    double term3 = 1.50475 * 1E-4 * (1 - pow(10, -8.2969 * ((T / T1) - 1)));
    cout << "term 3 = " << term3 << "pow~ = " << pow(10, -8.2969 * ((T / T1) - 1)) << endl;
    double term4 = 0.42873 * 1E-3 * (pow(10, 4.76955 * (1 - T1 / T)) - 1) + 0.78614;
    cout << "term 4 = " << term4 << "pow~ = " << (pow(10, 4.76955 * (1 - T1 / T)) - 1) << endl;
    cout << "logew = " << term1 - term2 + term3 + term4 << endl;
    return term1 - term2 + term3 + term4;
}

double calc_eW(double T0)
{
    cout << "eW" << pow(10, calcLogeW(T0)) << endl;
    return pow(10, calcLogeW(T0));
}

int main()
{
    printf("This is Wet/Dry-bulb temperature to \nDew point temperature & Relative humidity Calculator\n");
    printf("Please enter A, P, Dry, Wet-bulb temperature \nin scientific notation format\n");
    double tw, t0, Tw, T0, e0, ew, _e, U, Td, P, A;
    scanf("%le %le %le %le", &A, &P, &t0, &tw);
    T0 = t0 + T1;
    Tw = tw + T1;
    e0 = calc_eW(T0);
    ew = calc_eW(Tw);
    _e = ew - A * P * (T0 - Tw);
    U = _e / e0;
    //T0 - 0.1
    double Tr = T0;
    double er = calc_eW(Tr);
    while (abs(_e - er) > esp) {
        Tr -= delta;
        er = calc_eW(Tr);
    }
    Td = Tr - T1;
    printf("%le, %le\n", Td, U);

    return 0;
}

