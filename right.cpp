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
	int t, road[maxn];
	scanf("%d", &t);
	while (t--)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		int low = 0, high = 0; 
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &road[i]);
			high += road[i];
			if (road[i] > low)
				low = road[i];
		}
		while (low < high)    //二分，下界是最长路段，上界是路的总长
		{
			int mid = (low + high) / 2;
			int count = 1;    //需要的施工队
			int tmp = road[1];
			for (int i = 2; i <= m; i++)
			{
				if (tmp + road[i] > mid)
				{
					count++;
					tmp = road[i];
				}
				else
					tmp += road[i];
			}
			if (count > n)
				low = mid + 1;
			else
				high = mid;
		}
		printf("%d\n", low);
	}
    return 0;
}
