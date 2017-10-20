#include <iostream>
using namespace std;

void selection_sort(int arr[], int len) {
    int min = 0;
    for(int i = 0; i < len - 1; ++i) {
        min = i;
        for(int j = i + 1; j < len; ++j) 
            if(arr[min] > arr[j])
                min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int A[] {9, 8, 6, 4, 5, 4, 7, 6, 0, 2};
    selection_sort(A, 10);
    for(int i = 0; i < 10; ++i)
        cout << A[i] << endl;
}
