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
const int maxn = 1000005;
using namespace std;
char data[maxn], goal[maxn];
int myNext[maxn];
void getNext(const char goal[], int myNext[])
{
	int goalLen = strlen(goal);
	myNext[0] = -1;
	int i = 0, j = -1;
	while (i < goalLen - 1)
		if (j == -1 || goal[i] == goal[j])
			++j, ++i, myNext[i] = j;
		else
			j = myNext[j];
}
int kmp(const char data[], const char goal[], int myNext[])
{
	getNext(goal, myNext);
	int dataLen = strlen(data), goalLen = strlen(goal);
	int i = 0, j = 0;
	while (i < dataLen && j < goalLen)
		if (j == -1 || data[i] == goal[j])
			i++, j++;
		else
			j = myNext[j];
	return j == goalLen ? i - j + 1 : -1;
}
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> data[i];
		for (int i = 0; i < m; i++)
			cin >> goal[i];
		cout << kmp(data, goal, myNext) << endl;
	}
	return 0;
}
