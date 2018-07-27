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
const int maxn = 130005;
using namespace std;
//定义取模数
long long mod = llf;
struct Matrix
{
    long long a[2][2];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    Matrix operator*(const Matrix y)
    {
        Matrix ans;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= 1; k++)
                    ans.a[i][j] += a[i][k] * y.a[k][j];
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                ans.a[i][j] %= mod;
        return ans;
    }
    void operator=(const Matrix b)
    {
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                a[i][j] = b.a[i][j];
    }
};
long long matrixQuickPow(long long x)
{
    x--;
    Matrix ans, trs;
    ans.a[0][0] = ans.a[1][1] = 1;
    trs.a[0][0] = trs.a[1][0] = trs.a[0][1] = 1;
    while (x)
    {
        if (x & 1)
            ans = ans * trs;
        trs = trs * trs;
        x >>= 1;
    }
    return ans.a[0][0];
}
int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);

    return 0;
}
