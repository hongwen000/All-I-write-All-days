#include <algorithm>
#include <chrono>
#include <iostream>
#include "date/include/date/date.h"

int main()
{
    auto now = std::chrono::system_clock::now();
    std::cout << date::format("%S", now) << std::endl;
}
