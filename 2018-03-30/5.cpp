#include <algorithm>
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

#define FLOPPY_SECTOR_PER_TRACK 18
#define FLOPPY_TRACK_PER_HEAD 80
#define FLOPPY_HEAD_PER_DISK 2
void sys_read_disk( size_t logical_start_sector)
{
    size_t cylinder = logical_start_sector / (FLOPPY_HEAD_PER_DISK * FLOPPY_SECTOR_PER_TRACK);
    size_t head = (logical_start_sector % (FLOPPY_HEAD_PER_DISK * FLOPPY_SECTOR_PER_TRACK)) / FLOPPY_SECTOR_PER_TRACK;
    size_t sector = (logical_start_sector % (FLOPPY_HEAD_PER_DISK * FLOPPY_SECTOR_PER_TRACK)) % FLOPPY_SECTOR_PER_TRACK + 1;
    std::cout << "head" << head << std::endl;
    std::cout << "cylinder" << cylinder << std::endl;
    std::cout << "sector" << sector << std::endl;
}

int main()
{
    size_t lba;
    while(true)
    {
        std::cin >> lba;
        sys_read_disk(lba);
    }
}
