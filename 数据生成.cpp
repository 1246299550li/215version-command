#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <climits>
const int inf = 0x3f3f3f3f;
const int maxn = 50005;

using namespace std;
int main()
{
	//	freopen ("input.in", "r", stdin);
	freopen("input.in", "w", stdout);
	srand(time(0));
	int t = 15,
		n = 100000,
		m = 3;

	//    printf("%d %d\n", n, m);
	while (t--)
	{
		int r = rand() % 100;
		for (int i = 1; i <= r; i++)
		{
			int s = rand();
			if (s % 3)
				cout << "W";
			else
				cout << "L";
		}
		cout << endl;
	}

	// cout << 0;
	// for (int i = 1; i <= t; i++)
	// {
	// 	int l = (1 + rand()) * 7777;
	// 	int r = (1 + rand()) * 7777;
	// 	cout << l << " " << r << " " << rand() % min(l, r) << endl;
	// }

	return 0;
}
