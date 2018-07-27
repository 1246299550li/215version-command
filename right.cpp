#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
const long long llf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;
int datax[maxn], datay[maxn], data[maxn];
double compute(int a, int b)
{
	double tmp1 = datax[a] * datax[b] + datay[a] * datay[b];
	double tmp2 = datax[a] * datax[a] + datay[a] * datay[a];
	double tmp3 = datax[b] * datax[b] + datay[b] * datay[b];
	if (tmp1 >= 0)
		return (tmp1 * tmp1) / (tmp2 * tmp3);
	else
		return -((tmp1 * tmp1) / (tmp2 * tmp3));
}
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int n;
	cin >> n;
	datax[0] = 1, datay[0] = 0; 
	for (int i = 1; i <= n; i++)
	{
		cin >> datax[i] >> datay[i];
		data[i] = compute(0, i);
	}
	

	return 0;
}
