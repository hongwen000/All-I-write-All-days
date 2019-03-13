#include <chrono>
#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace Eigen;
using namespace std;
static int values[8][8] =
   {{ 30, -25, 10, 5, 5, 10, -25,  30,},
    {-25, -25,  1, 1, 1,  1, -25, -25,},
    { 10,   1,  5, 2, 2,  5,   1,  10,},
    {  5,   1,  2, 1, 1,  2,   1,   5,},
    {  5,   1,  2, 1, 1,  2,   1,   5,},
    { 10,   1,  5, 2, 2,  5,   1,  10,},
    {-25, -25,  1, 1, 1,  1, -25, -25,},
    { 30, -25, 10, 5, 5, 10, -25,  30,}};

static const int grid[8][8] = 
   {{ 1, 1, 1, 1, 0, 0, 0, 0},
    { 1,-1, 1, 1, 1,-1, 0, 0},
    { 1,-1, 1, 1, 1,-1,-1,-1},
    { 1,-1, 1, 1, 1,-1,-1,-1},
    { 1,-1,-1, 1, 1, 1,-1,-1},
    { 1,-1,-1, 1, 1, 1,-1,-1},
    { 1, 0, 1, 1, 1, 1, 0, 0},
    { 1, 1, 1, 1, 1, 1, 0, 0}};

Array<int, 8, 8> EV;
Array<int, 8, 8> EG;

int getv(int arg)
{
    int ret = 0;
    values[arg%8][0] = arg;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            ret += values[i][j] * grid[i][j];
        }
    }
    return ret;
}

int getv2(int arg)
{
    if(arg!=0)
        EV(arg%8,0) = arg;
    int ret = 0;
    ret += (EV * EG).sum();
    return ret;
}

int main()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            EV(i,j) = values[i][j];
            EG(i,j) = grid[i][j];
        }
    }

    int times = 1000000;
    int ret, i;
    decltype(chrono::steady_clock::now()) st, et;
    st = chrono::steady_clock::now();
    for(i = 0; i < times; ++i)
    {
        ret =  getv(i);
    }
    et = chrono::steady_clock::now();
    cout << (et - st).count() << endl;
    st = chrono::steady_clock::now();
    for(i = 0; i < times; ++i)
    {
        if(i == 0)
        {
            cout << ret;
            ret =  getv2(i);
        }
        ret =  getv2(i);
    }
    et = chrono::steady_clock::now();
    cout << (et - st).count() << endl;
}
