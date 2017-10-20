#include <iostream>
using namespace std;

void reverse(int* A, int lo, int hi) {
    if(lo < hi) {
        std::swap(A[lo], A[hi - 1]);
        reverse(A, lo + 1, hi - 1);
    }
}

void reverse2(int *A, int lo, int hi) {
    hi -= 1;
    while(lo < hi) std::swap(A[lo++], A[hi--]);
};

int main() {
    int A[] {9, 0, 1, 2, 4, 5};
    reverse2(A, 0, 6);
    for(int i = 0; i < 6; ++i)
        cout << A[i] << endl;
}
