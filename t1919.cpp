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
int dp[205][205][2];
int a[205][205];
int give[205][205];
int pre_sum[205][205];
int sta[205];
int n, m, money;
int main()
{
    while (~scanf("%d%d%d", &n, &m, &money))
    {
        if (!n && !m && !money)
            return 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= money; j++)
            {
                dp[i][j][0] = 0;
                dp[i][j][1] = -inf;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                give[i][j] = 0;
            }
        int t;
        scanf("%d", &t);
        while (t--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            give[x][y] = 1;
        }
        memset(sta, 0, sizeof(sta));
        memset(pre_sum, 0, sizeof(pre_sum));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            sta[i] = 1;
            while (sta[i] <= m && give[i][sta[i]])
            {
                ans += a[i][sta[i]];
                sta[i]++;
            }
            for (int j = m; j >= 1; j--)
            {
                pre_sum[i][j] = give[i][j] ? (pre_sum[i][j + 1] + a[i][j]) : 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= money; j++)
            {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];

                int cnt = 0;
                int va = 0;
                for (int k = sta[i]; k <= m; k++)
                {
                    va += a[i][k];
                    if (!give[i][k])
                    {
                        cnt++;
                        if (cnt > j)
                            break;
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - cnt][0] + va + pre_sum[i][k + 1]);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - cnt][0] + va);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - cnt][1] + va + pre_sum[i][k + 1]);
                    }
                }
            }
        }
        if (dp[n][money][1] + ans < 0)
            cout << dp[n][money][0] + ans << endl;
        else
            cout << dp[n][money][1] + ans << endl;
    }
    return 0;
}
