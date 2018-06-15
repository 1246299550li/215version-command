#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1001;
int vis[N];
int bfs(vector<int> vec[], int x)
{
    int sumn = 0;
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < (int)vec[x].size(); i++)
        {
            if (!vis[vec[x][i]])
            {
                sumn++;
                vis[vec[x][i]] = 1;
                q.push(vec[x][i]);
            }
        }
    }
    return sumn;
}
int main()
{
    int n, k, m, x, y, ans;
    while (~scanf("%d%d%d", &n, &k, &m))
    {
        vector<int> vec[N];
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            vec[x].push_back(y);
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
            if (bfs(vec, i) >= (n - k))
                ans++;
        if (ans >= k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}