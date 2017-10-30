#define E 2.718281828 
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstdlib>

void TD2H (double temperature, double dewpoint) {
    double e = 6.11 * std::pow(E, 5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
    double h = 0.5555 * (e - 10.0);
    double humidex = temperature + h;
    std::cout << std::fixed << std::setprecision(1) << "T " << temperature << " D " << dewpoint << " H " << humidex << std::endl;
}

void TH2D (double temperature, double humidex) {
    double h = humidex - temperature;
    double e = h / 0.5555 + 10;
    double tmp1 = std::log(e / 6.11) / 5417.7530;
    double tmp2 = tmp1 - (1/273.16);
    double tmp3 = 1 / tmp2;
    double dewpoint = tmp3 - 273.16;
    std::cout << std::fixed << std::setprecision(1) << "T " << temperature << " D " << dewpoint << " H " << humidex << std::endl;
}

void DH2T (double dewpoint, double humidex) {
    double e = 6.11 * std::pow(E, 5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
    double h = 0.5555 * (e - 10.0);
    double temperature = humidex - h;
    std::cout << std::fixed << std::setprecision(1) << "T " << temperature << " D " << dewpoint << " H " << humidex << std::endl;
}

int main() {
    std::string str;
    std::string s1, s2, s3, s4;
    while(std::getline(std::cin, str)) {
        if(str == "E")
            break;
        std::stringstream ss(str);
        ss >> s1 >> s2 >> s3 >> s4;
        if(s1 == "T" && s3 == "D") 
            TD2H(std::atof(s2.c_str()), std::atof(s4.c_str()));
        else if(s1 == "T" && s3 == "H") 
            TH2D(std::atof(s2.c_str()), std::atof(s4.c_str()));
        else if(s1 == "D" && s3 == "H") 
            DH2T(std::atof(s2.c_str()), std::atof(s4.c_str()));
        else if(s1 == "D" && s3 == "T") 
            TD2H(std::atof(s4.c_str()), std::atof(s2.c_str()));
        else if(s1 == "H" && s3 == "T") 
            TH2D(std::atof(s4.c_str()), std::atof(s2.c_str()));
        else
            DH2T(std::atof(s4.c_str()), std::atof(s2.c_str()));
    }
    return 0;
}

