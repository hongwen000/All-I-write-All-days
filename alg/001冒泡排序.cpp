#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
void bubblesort1A(int A[], int n) {
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 1; i < n; ++i) {
            if(A[i - 1] > A[i]) {
                std::swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
    --n;
    }
}
void bubblesort1B(int A[], int n) {
    for(int i = 0; i < n; ++i) {
        //每次最大的元素会被交换到最后面，已经放到最后的有i个，又每次比较时第j个元素和第j+1个元素比，因此j < n - i - i
        for(int j = 0; j < n - 1 - i; ++j) {
            if(A[j] > A[j+1]) {
                std::swap(A[j], A[j+1]);
            }
        }
    }
}
int main() {
    int A[] = {3,13,34,557,121,35,1,45,7,12};
    bubblesort1A(A, std::size(A));
    for(auto it = std::begin(A); it != std::end(A); ++it)
        std::cout << *it << ' ';
}

