#include <vector>
using namespace std;
int max(const int a, const int b)
{
	return a>b?a:b;
}
int getMaxCuttingPrice(int prices[][2], int priceCount, int rodLength)
{
	int c[6];
	int w[6];
	int N = 6;
	int V = rodLength;
	for (int i = 0; i < N; i++)
	{
		c[i]=prices[i][0];
		w[i]=prices[i][1];
	}
	vector<int> f(V + 1);
	for (int i = 0; i <= N; i++)
	{
		f[i] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = c[i - 1]; j <=V; j++)
		{
			f[j] = max(f[j], f[j - c[i - 1]] + w[i - 1]);
		}
	}
	return  f[V];
}
