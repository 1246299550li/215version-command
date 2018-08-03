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
pair<int, int> pre[5][5];
vector<pair<int, int>> fun()
{
	int mymap[5][5];
	int isvis[5][5];
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			cin >> mymap[i][j];
			isvis[i][j] = 0;
		}
	stack<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int tmpx, tmpy;
		tie(tmpx, tmpy) = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (tmpx + dx[i] >= 0 && tmpy + dy[i] >= 0 && tmpx + dx[i] < 5 && tmpy + dy[i] < 5)
				if (!isvis[tmpx + dx[i]][tmpy + dy[i]] && !mymap[tmpx + dx[i]][tmpy + dy[i]])
				{
					q.push(make_pair(tmpx + dx[i], tmpy + dy[i]));
					isvis[tmpx + dx[i]][tmpy + dy[i]] = 1;
					pre[tmpx + dx[i]][tmpy + dy[i]] = make_pair(tmpx, tmpy);
					if (tmpx + dx[i] == 4 && tmpy + dy[i] == 4)
					{
						vector<pair<int, int>> ans;
						while (!q.empty())
						{
							ans.push_back(q.top());
							q.pop();
						}
						return ans;
					}
				}
		}
	}
}
int main()
{
	freopen("input.in", "r", stdin);
	freopen("input.out", "w", stdout);
	vector<pair<int, int>> a = fun();
	for (int pos = a.size() - 1; pos >= 0; pos--)
		cout << "(" << a[pos].first << "," << a[pos].second << ")" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << pre[i][j].first << "," << pre[i][j].second << " ";
		cout << endl;
	}
	
	return 0;
}
