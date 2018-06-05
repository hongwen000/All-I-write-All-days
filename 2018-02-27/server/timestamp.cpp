#include "timestamp.h"

std::string getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%F %H:%M") << ':';
    ss << date::format("%S", now);
    auto s = ss.str();
    return s;
}


