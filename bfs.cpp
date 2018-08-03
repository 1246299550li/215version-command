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
const int maxn = 505;
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
	freopen("input.in", "r", stdin);
	freopen("input1.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	char data[maxn][maxn], a[maxn][maxn];
	bool isVis[maxn][maxn];
	for (int i = 0; i < n; i++)
		scanf("%s", &data[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (data[i][j] == '*')
			{
				memset(isVis, 0, sizeof(isVis));
				queue<pair<int, int>> oil;
				int ans = 1;
				oil.push(make_pair(i, j));
				isVis[i][j] = 1;
				while (!oil.empty())
				{
					int x, y;
					tie(x, y) = oil.front();
					oil.pop();
					for (int k = 0; k < 4; k++)
					{
						int tmpx = x + dx[k], tmpy = y + dy[k];
						if (tmpx >= 0 && tmpy >= 0 && tmpx < n && tmpy < m)
							if (data[tmpx][tmpy] == '.' && !isVis[tmpx][tmpy])
							{
								isVis[tmpx][tmpy] = 1;
								oil.push(make_pair(tmpx, tmpy));
								ans++;
							}
					}
				}
				a[i][j] = '0' + (ans % 10);
			}
			else
			{
				a[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", a[i]);
	return 0;
}