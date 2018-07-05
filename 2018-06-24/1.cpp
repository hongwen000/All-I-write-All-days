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
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;
const char *inputs[] = {"mv", "USR4.ELF", "UUU.ELF"};
struct input_cmd_t {
  int start = 0;
};
char buf__[20];
size_t pos;
void write(int fd, uint8_t *buf, size_t len) { buf__[pos++] = *buf; }
int main(int argc, const char *argv[]) {
  int fd = 0;
  input_cmd_t input_cmd;
  uint8_t ch;
  size_t ext = 0;
  bool before_ext = true;
  for (size_t i = 0; i < 8; ++i) {
    auto fn = inputs[input_cmd.start + 2];
    if (i < strlen(fn) && fn[i] != '.' && before_ext) {
      ch = fn[i];
    } else {
      if (before_ext && i + 1 < strlen(fn))
        ext = i + 1;
      before_ext = false;
      ch = ' ';
    }
    write(fd, &ch, 1);
  }
  for (size_t i = 0; i < 3; ++i) {
    auto fn = inputs[input_cmd.start + 2] + ext;
    if (ext && i < strlen(fn)) {
      ch = fn[i];
    } else {
      ch = ' ';
    }
    write(fd, &ch, 1);
  }
  cout << buf__ << endl;
  return 0;
}
