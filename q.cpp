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
const int maxn = 200005;
using namespace std;
bool isvis[maxn];
int solve(int n, int k)
{
    if (k < n)
        cout << n - k - 1 << endl;
    queue<pair<int, int>> q;
    memset(isvis, 0, sizeof(isvis));
    q.push(make_pair(n, 0));
    isvis[n] = 1;
    while (!q.empty())
    {
        pair<int, int> point = q.front();
        q.pop();
        int num = point.first, step = point.second;
        if (num - 1 == k || num + 1 == k || num * 2 == k)
            return step + 1;
        if (num + 1 < maxn && !isvis[num + 1])
        {
            q.push(make_pair(num + 1, step + 1));
            isvis[num + 1] = 1;
        }
        if (num * 2 < maxn && !isvis[num * 2])
        {
            q.push(make_pair(num * 2, step + 1));
            isvis[num * 2] = 1;
        }
        if (num - 1 >= 0 && !isvis[num - 1])
        {
            q.push(make_pair(num - 1, step + 1));
            isvis[num - 1] = 1;
        }
    }
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("input.out", "w", stdout);
    int n, k;
    while (cin >> n >> k)
    {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}