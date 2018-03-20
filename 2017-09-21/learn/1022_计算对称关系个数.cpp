#include <cmath>
//returns the number of symmetric relations on a set of n elements.
int count_symmetric(int n){
    return pow(2, n * (n + 1) / 2);
}
