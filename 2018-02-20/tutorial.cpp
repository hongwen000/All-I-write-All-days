#include <iostream>
#include <cmath>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
using namespace std;
int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Version " << Tutorial_VERSION_MAJOR 
            << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage " << argv[0] << " number" << std::endl;
        return 1;
    }
    double inputValue = stod(string(argv[1]));
#ifdef USE_MYMATH
    std::cout << "Using MYMATH" << std::endl;
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif
    std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
    return 0;
}
