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
const int maxn = 10005;
using namespace std;
int data[maxn];
int main()
{
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	int n, q;
	while (cin >> n >> q)
	{
		if (0 == n)
			break;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			data[tmp]++;
		}
		int ans = 0;
		for (int i = 0; i < q; i++)
		{
			cout << "CASE# " << i + 1 << ":" << endl;
			cin >> tmp;
			for (int i = 0; i < tmp; i++)
			{
				ans += data[i];
			}
			ans++;
			if (data[tmp])
				cout << tmp << "not found" << endl;
			else
			{
				cout << q << " found at " << ans << endl;
			}
		}
	}
	return 0;
}
