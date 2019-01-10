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
int data[10];
int p[15][15];
int ans, maxAns;
void dfs()
{
    if (maxAns >= 36)
        return;
    int i, j, sum;
    for (i = 1; i < 10; i++)
    {
        if (data[i] < 0)
            continue;
        for (j = 1; j < 10 - i; j++)
        {
            sum = i + j;
            if (data[j] < 0)
                continue;
            if (i == j && data[i] > 1 && data[sum] > 0 && !p[i][j])
            {
                data[i]--, data[j]--, data[sum]--;
                ans++;
                maxAns = max(ans, maxAns);
                p[i][j] = 1;
                dfs();
                data[i]++, data[j]++, data[sum]++;
                p[i][j] = 0;
                ans--;
            }
            if (i != j && data[i] > 0 && data[j] > 0 && data[sum] > 0 && !p[i][j])
            {
                data[i]--, data[j]--, data[sum]--;
                ans++;
                maxAns = max(ans, maxAns);
                p[i][j] = 1;
                dfs();
                data[i]++, data[j]++, data[sum]++;
                p[i][j] = 0;
                ans--;
            }
        }
    }
}
int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int tot = 0;
    while (t--)
    {
        for (int i = 1; i < 10; i++)
            cin >> data[i];
        ans = 0, maxAns = 0;
        memset(p, 0, sizeof(p));
        dfs();
        cout << "Case #" << ++tot << ": " << maxAns << endl;
    }
    return 0;
}
