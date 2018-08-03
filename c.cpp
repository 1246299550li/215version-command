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
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			sum[i] = sum[i - 1] + tmp;
			dp[i][i] = 0;
		}
	}
	return 0;
}
