#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
long long f[50][50];
// 第一类斯特林数
int main()
{
    cin >> n >> m;
    f[1][1] = 1;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 1;
        f[i][0] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] =f[i - 1][j - 1] - f[i - 1][j] * (i - 1);
        }
    }
    cout << f[n][m] << ends;
    system("pause");
    return 0;
}