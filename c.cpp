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
const int maxn = 105;
using namespace std;
int dp[maxn][maxn];
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int n, data[maxn];
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &data[i]);
		for (int len = 2; len < n; len++)
			for (int start = 2; start + len - 1 <= n; start++)
			{
				int end = start + len - 1;
				dp[start][end] = inf;
				for (int k = start; k < end; k++)
					dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + data[start - 1] * data[k] * data[end]);
			}
		printf("%d\n", dp[2][n]);
	}
	return 0;
}
