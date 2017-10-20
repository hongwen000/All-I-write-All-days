#include <iostream>
using namespace std;
template<int N>
class Loop {
public:
  static inline int Run() {
    int v = Loop<N - 1>::Run();
    cout << v;
    return v + 1;
  }
};

template<>
class Loop<0> {
public:
  static inline int Run() {
    return 0;
  }
};

int main()
{
    Loop<8>::Run();
}
