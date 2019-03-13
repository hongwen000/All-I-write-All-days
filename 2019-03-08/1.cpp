#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

struct  { int Nv;string VN[10];} Vns={3,"E","T","F"};
struct  { int Nt;string VT[10];} Vts={7,"+","-","*","/","(",")","i"};
struct  { int Np;string PL[20],PR[20];} ps={0};
string S="E"; 

int get_idx(const string& s)
{
    for(int i = 0; i < Vns.Nv; ++i)
    {
        if(s == Vns.VN[i])
        {
            return i;
        }
    }
    return -1;
}

void init_PL()
{
    ps.Np = Vns.Nv;
    for(int i = 0; i < Vns.Nv; ++i)
    {
        ps.PL[i] = Vns.VN[i];
    }
}

int main()
{
    init_PL();
    FILE* p = fopen("1.in", "r");
    int N = 0;
    fscanf(p, "%d", &N);
    char L[10], R[10];
    while(N--)
    {
        fscanf(p, "%s%s", L, R);
        ps.PR[get_idx(L)] += " | ";
        ps.PR[get_idx(L)] += R;
    }
    cout << "G[" << S << "]:" << endl;
    for(int i = 0; i < Vns.Nv; ++i)
    {
        ps.PR[i][0] = ':';
        ps.PR[i][1] = ':';
        ps.PR[i][2] = '=';
        cout << ps.PL[i] << "" << ps.PR[i] << endl;
    }
}