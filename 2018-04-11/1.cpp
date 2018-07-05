#include <algorithm>
#include <time.h>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;

int main()
{
    char bufin[2];
    std::cin >> bufin;
    char buf[128];
    memset(buf, 0, 128);
    sscanf(bufin, "%2c", buf);
    sscanf(bufin,"%2c", buf + 2);
    std::cout << buf << std::endl;
    clock_t a;
}
