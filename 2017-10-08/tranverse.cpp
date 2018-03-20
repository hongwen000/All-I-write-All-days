#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

struct Matrix {
    int mu, nu, tu;
    std::vector<std::tuple<int, int, int>> v;
};

void tranverse(Matrix M, Matrix T) {
    T.mu = M.mu;
    T.nu = M.nu;
    T.tu = M.tu;
    if(M.tu > 0) {
        int p = 0;
        for(int col = 0; col < M.nu; ++col) {
            for(int q = 0; q < M.tu; ++q) {
                if(std::get<1>(M.v[q]) == col){
                    T.v.push_back(std::tuple<int, int, int>(std::get<1>(M.v[q]), std::get<0>(M.v[q]), std::get<2>(M.v[q])));
                    ++p;
                }
            }
        }
    }
}
int main() {

}
