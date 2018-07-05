#include <thread>

using namespace std;

int flag = 0;

int main() {

  auto t1 = thread([&]() {
    flag = 1;
  });
  auto t2 = thread([&]() {
    flag = 2;
  });

  t1.join();
  t2.join();

  return 0;
}
