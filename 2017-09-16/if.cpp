#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string
using namespace std;
using namespace std::experimental::filesystem;

std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    return ss.str();
}
int main()
{
    path directory ("/mnt/c/Users/lixin/Desktop/ACM-ICPC/");
    directory /= return_current_time_and_date();
    create_directory(directory);
}
