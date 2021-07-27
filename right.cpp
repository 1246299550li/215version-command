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
const int maxn = 1050;
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
char data[maxn][maxn];
int myhash[maxn][maxn];
bool isVis[maxn][maxn];
int sum[maxn];
int hashCot = 0;
void dfs()
{
	
}
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> data[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (data[i][j] == '.' && !isVis[i][j])
			{
				hashCot++;
				queue<pair<int, int>> oil;
				oil.push(make_pair(i, j));
				myhash[i][j] = hashCot;
				isVis[i][j] = 1;
				int count = 1;
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
								myhash[tmpx][tmpy] = hashCot;
								count++;
							}
					}
				}
				sum[hashCot] = count;
			}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (data[i][j] == '*')
			{
				set<int> h;
				int ans = 1;
				for (int k = 0; k < 4; k++)
				{
					int tmpx = i + dx[k], tmpy = j + dy[k];
					if (tmpx >= 0 && tmpy >= 0 && tmpx < n && tmpy < m)
						if (!h.count(myhash[tmpx][tmpy]))
						{
							h.insert(myhash[tmpx][tmpy]);
							ans += sum[myhash[tmpx][tmpy]];
						}
				}
				printf("%d", ans % 10);
			}
			else
				printf(".");
		printf("\n");
	}
	return 0;
}