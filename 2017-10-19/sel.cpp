#include <iterator>
#include <iostream>
using namespace std;
void selection_sort(int arr[], int len) {
    int dest[len];
    int min = 0;
    int i = 0, j;
    while(i < len - 1) {
        min = i;
        j = i + 1;
        while(j < len) {
            if(arr[min] > arr[j])
                min = j;
            ++j;
        }
        dest[i] = arr[min];
        ++i;
    }
    dest[i] = arr[i];
    for(int i = 0; i < len; ++i)
        cout << dest[i] << endl;
}
int main() {
    int arr[] = {3, 2, 1};
    selection_sort(arr, std::size(arr));
}
