#include <algorithm>
#include <iostream>
using namespace std;
//Adjacency Matrix
#define MAX_V_NUM 200
struct Matrix_Graph {
    int vex_num;
    bool M[MAX_V_NUM][MAX_V_NUM];
};

int main()
{
    Matrix_Graph g;
    g.vex_num = 10;
    g.M[0][1] = true;
    cout << "ff" << endl;
    int a;
    cin >> a;
    cout << a << endl;
    cout << "ff" << endl;
    cout << "ffg" << endl;
}