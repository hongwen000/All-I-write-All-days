#include <iostream>

template<int N>
class Factorial {
public:
  constexpr static int RESULT = N * Factorial<N - 1>::RESULT ;
};

template<>
class Factorial<1> {
public:
    constexpr static int RESULT = 1;
};

int main(int argc, char ** argv) {
  try {
    std::cout << Factorial<10>::RESULT << std::endl;
  } catch(std::exception const& e) {
    std::cerr << e.what() << std::endl;
  }
}
