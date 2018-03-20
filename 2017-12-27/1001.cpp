#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;

void radixsort(int data[], int n)
{
    int mx = *std::max_element(data, data + n);
    int e = 0;
    while(mx / pow(10, e))
    {
        std::sort(data, data + n, [e](auto d1, auto d2){
                return (d1 / (int) pow(10, e)) % 10 < (d2 / (int) pow(10, e)) % 10;
                });
        ++e;
    }
}

int main()
{
    int data[] = {9,6,7,22,20,33,16,20};
    cout << "Before sorted:" << endl;
    for(int i=0; i<=7; i++)
        cout<<data[i]<<" ";
    cout<<endl;

    cout << "After sorted:" << endl;
   radixsort(data,8);
    for(int i=0; i<=7; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    return 0;
}
