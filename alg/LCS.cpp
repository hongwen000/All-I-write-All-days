#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char A[10000], B[10000];
static int  N[10000 + 1][10000 + 1];
int main() {
    cin >> A >> B;
    int lenA = strlen(A);
    int lenB = strlen(B);
    int i, j;
    for(i = 1; i <= lenA; ++i) {
        for(j = 1; j <= lenB; ++j) {
            if(A[i - 1] == B[j - 1])
                N[i][j] = N[i - 1][j - 1] + 1;
            else
                N[i][j] = std::max(N[i - 1][j], N[i][j - 1]);
        }
    }
    cout << N[lenA][lenB] << endl;
}
