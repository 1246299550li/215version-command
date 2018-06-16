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
const int P = 1e8 + 7;
// 所以当n<0时，输出”No”；
// 当n>0时：
// 若n为奇数，m=(an)2+1
// 若n为偶数，m=(an)2
// [an an−1]=[21 10][an−1 an−2]=[21 10]n−2 [a2a1]
struct Matrix
{
    long long data[2][2];
    Matrix()
    {
        memset(data, 0, sizeof(data));
    }
    Matrix operator*(const Matrix y)
    {
        Matrix ans;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= 1; k++)
                    ans.data[i][j] += data[i][k] * y.data[k][j];
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                ans.data[i][j] %= P;
        return ans;
    }
    void operator=(const Matrix b)
    {
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                data[i][j] = b.data[i][j];
    }
};

int quick_pow(long long x)
{
    Matrix ans, trs;
    long long nn = x + 2;
    ans.data[0][0] = 1;
    ans.data[1][1] = 1;
    trs.data[0][0] = 2;
    trs.data[1][0] = 1;
    trs.data[0][1] = 1;
    while (x)
    {
        if (x & 1)
            ans = ans * trs;
        trs = trs * trs;
        x >>= 1;
    }
    long long an = (ans.data[0][0] * 3 + ans.data[0][1]) % P;
    if (nn % 2)
        return (an * an + 1) % P;
    else
        return (an * an) % P;
}

int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    long long n;
    while (~scanf("%lld", &n))
        if (n < 0)
            cout << "No" << endl;
        else if (n == 0)
            cout << "1" << endl;
        else if (n == 1)
            cout << "2" << endl;
        else if (n == 2)
            cout << "9" << endl;
        else
            cout << quick_pow(n - 2) << endl;
    return 0;
}
