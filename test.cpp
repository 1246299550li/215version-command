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
using namespace std;

int a[50005], b[50005];
// 找第k大的数
bool judge(vector<int> &a, vector<int> &b, const long long k, const long long x)
{
    long long sum = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
        sum += upper_bound(b.begin(), b.end(), x - *it) - b.begin();
    return sum < k;
}
int main()
{
    freopen("input.in", "r", stdin);
    // freopen ("input.out", "w", stdout);
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long l = a.front() + b.front(), r = a.back() + b.back() + 1;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            if (judge(a, b, k, mid))
                l = mid + 1;
            else
                r = mid;
        }
        printf("%lld\n", l);
        printf("%lld\n", l);
    }
    return 0;
}
