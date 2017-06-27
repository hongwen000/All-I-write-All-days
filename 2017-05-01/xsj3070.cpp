#include <math.h>
#include <stdio.h>

const double T1 = 273.15;
const double esp = 0.1;
const double delta = 0.5;

double calcLogeW(double T) //According to Goff Equation, calculate lg eW(T)
{
    double term1 = 10.79574 * (1 - T1 / T);
    double term2 = 5.02800 * log10(T / T1);
    double term3 = 1.50475 * 1E-4 * (1 - pow(10, -8.2969 * ((T / T1) - 1)));
    double term4 = 0.42873 * 1E-3 * (pow(10, 4.76955 * (1 - T1 / T)) - 1) + 0.78614;
    return term1 - term2 + term3 + term4;
}

double calc_eW(double T0) //Calculate eW(T)
{
    return pow(10, calcLogeW(T0));
}

double fp(double P) //Calculate fp
{
    return 1.0016 + 3.15 * 10E-6 * P - 0.074 / P;
}

int main()
{
    printf("This is Wet/Dry-bulb temperature to \nDew point temperature & Relative humidity Calculator\n");
    printf("Please enter A, P, Dry, Wet-bulb temperature \nin scientific notation format\n");
    double tw, t0, Tw, T0, e0, ew, _e, U, Td, P, A;
    scanf("%le %le %le %le", &A, &P, &t0, &tw);
    T0 = t0 + T1;
    Tw = tw + T1;
    e0 = calc_eW(T0) * fp(P); //e0 is real saturation vapor pressure
    ew = calc_eW(Tw) * fp(P);
    _e = ew - A * P * (T0 - Tw); //_e is real vapor pressure
    U = _e / e0;
    double Tr = T0;
    double er = calc_eW(Tr) * fp(P);
    while (abs(_e - er) > esp) {
        Tr -= delta;
        er = calc_eW(Tr) * fp(P);
    }
    Td = Tr - T1;
    printf("%le, %le\n", Td, U);
    return 0;
}

