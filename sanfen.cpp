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
const int maxn = 1005;
using namespace std;
double f_(double x)
{
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * x * x + 10 * x;
}

double f(double x, double y)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * x * x - y * x;
}

int main()
{
    int T;
    double y, left, right, mid;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &y);
        left = 0, right = 100;
        for (int i = 1; i <= 100; i++)
        {
            mid = (left + right) / 2;
            if (f_(mid) > y)
                right = mid;
            else
                left = mid;
        }
        printf("%.4f\n", f(mid, y));
    }
    return 0;
}
