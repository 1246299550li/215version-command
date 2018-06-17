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
const long long llf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
//¿ìËÙÃÝ 
using namespace std;
const long long p = 1000000007;
long long quick_mod(long long a, long long b)
{
	long long ans = 1;
	a %= p;
	while (b)
	{
		if(b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}
long long factorial_mod(long long a, long long b)
{
	long long ans = 1;
	for (long long i = a; i <= b; i++)
	{
		ans = ans * i % p;
	}
	return ans;
}
int main()
{
//	freopen ("input.in", "r", stdin);
//	freopen ("input.out", "w", stdout);
	int T;
	scanf("%d", &T);
	long long n, m, r, cot = 0;
	while(T--)
	{
		scanf("%lld%lld%lld", &n, &m, &r);
		long long ans = factorial_mod(m - r + 1, m) * quick_mod(r - 1, n - r) % p;
		printf("Case #%lld: %lld\n", ++cot, ans);
	}
	return 0;
}

