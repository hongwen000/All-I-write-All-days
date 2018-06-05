#include<cstdio>
#include<iostream>
#include<cmath>
#include<memory.h>
#define N 400010
using namespace std;
const double pi=acos(-1);
struct complex{
    double x,i;
    complex(){}
    complex(double x,double i):x(x),i(i){}
    complex operator+(complex a) {return complex(x+a.x,i+a.i);}
    complex operator-(complex a) {return complex(x-a.x,i-a.i);}
    complex operator*(complex a) {return complex(x*a.x-i*a.i,x*a.i+i*a.x);}
}a[N],b[N];
int n,m,i,nn;
void fft(complex *a,int n,int t)
{
    if (n==1) return;
    complex a0[n>>1],a1[n>>1];
    for (int i=0;i<n;i+=2) a0[i>>1]=a[i],a1[i>>1]=a[i+1];
    fft(a0,n>>1,t);fft(a1,n>>1,t);
    complex wn(cos(2*pi/n),t*sin(2*pi/n)),w(1,0);
    for (int i=0;i<(n>>1);i++,w=w*wn) a[i]=a0[i]+w*a1[i],a[i+(n>>1)]=a0[i]-w*a1[i];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    for (i=0;i<=n;i++) scanf("%lf",&a[i].x);
    for (i=0;i<=m;i++) scanf("%lf",&b[i].x);
    nn=1;while (nn<=n+m) nn<<=1;
    fft(a,nn,1);fft(b,nn,1);
    for (i=0;i<=nn;i++) a[i]=a[i]*b[i];
    fft(a,nn,-1);
    for (i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/nn+0.5));
}

