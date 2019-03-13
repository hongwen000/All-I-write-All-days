#include <string>
#include <iostream>
#include <cstdio>
using namespace std;


FILE* p = fopen("22.in", "r");
struct  { int Nv;string VN[10];} Vns={0};
struct  { int Nt;string VT[10];} Vts={0};
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

void input_N()
{
    int n;
    char c[2];
    fscanf(p, "%s", c);
    S = c;
    fscanf(p, "%d", &n);
    Vns.Nv = n;
    for(int i = 0; i < Vns.Nv; ++i)
    {
        fscanf(p, "%s",c);
        Vns.VN[i] = c;
    }
    fscanf(p, "%d", &n);
    Vts.Nt = n;
    for(int i = 0; i < Vts.Nt; ++i)
    {
        fscanf(p, "%s", c);
        Vts.VT[i] = c;
    }
}

void input_P()
{
    int N = 0;
    fscanf(p, "%d", &N);
    char L[10], R[10];
    while(N--)
    {
        fscanf(p, "%s%s", L, R);
        ps.PR[get_idx(L)] += " | ";
        ps.PR[get_idx(L)] += R;
    }
}

void output()
{
    cout << "G[" << S << "]:" << endl;
    for(int i = 0; i < Vns.Nv; ++i)
    {
        ps.PR[i][0] = ':';
        ps.PR[i][1] = ':';
        ps.PR[i][2] = '=';
        cout << ps.PL[i] << "" << ps.PR[i] << endl;
    }
}

int main()
{
    input_N();
    init_PL();
    input_P();
    output();
}
