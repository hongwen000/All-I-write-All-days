#include <stdio.h>
#include <math.h>

const double T1 = 273.16;
static double P  = 1.013E5;
const double A  = 8.57E-3;

double calcLogeW(double T) 
{
    double term1 = 10.79574 * (1 - T1 / T);
    double term2 = 5.02800 * log(T / T1);
    double term3 = 1.50475 * 1E-4 * (1 - pow(10, -8.2969 * (T / (T1 - 1))));
    double term4 = 0.42873 * 1E-3 * (pow(10, 4.76955 * (1 - T1 / T)) - 1) + 0.78614;
    return term1 - term2 + term3 + term4;
}

double calc_e(double T, double Tw)
{
    double logeW = calcLogeW(Tw);
    double _eW   = exp(logeW);
    double _e    = _eW - A * P * (T - Tw);
    return _e;
}

double calcWB(double _e)
{
    double WB;
    //Unable to implement, Did not learn the iteration of polynomials
    return WB;
}

double calcR(double T, double _e)
{
    double eW = exp(calcLogeW(T));
    return _e / eW;
}

int main()
{
    printf("This is Wet/Dry-bulb temperature to \nDew point temperature & Relative humidity Calculator\n");
    printf("Please enter P, Wet, Dry-bulb temperature in scientific notation format\n");
    double Tw, T, DP_temp, R_humidity, _e;
    while(scanf("%le, %le, %le", &P, &T, &Tw)) {
        _e = calc_e(T, Tw);
        DP_temp = calcWB(_e);
        R_humidity = calcR(T, _e);
        printf("%le, %le\n", DP_temp, R_humidity);
    }
    return 0;
}
        
