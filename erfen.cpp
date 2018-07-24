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
double y;
double f(double x)
{
    return 8.0 * pow(x, 4) + 7.0 * pow(x, 3) + 2.0 * pow(x, 2) + 3.0 * x + 6.0 - y;
}
int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        cin >> y;
        double low = 0, high = 100;
        if (y < 6 || y > 807020306)
            printf("No solution!\n");
        else
        {
            double mid;
            while (high - low >= 1e-8)
            {
                mid = (low + high) / 2.0;
                if (f(mid) > 0)
                    high = mid;
                else
                    low = mid;
            }
            printf("%.4f\n", mid);
        }
    }
    return 0;
}
