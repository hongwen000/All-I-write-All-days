#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
 
int main()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%FT%T%z") << '\n';
    std::cout << ss.str().size() << std::endl;
}
