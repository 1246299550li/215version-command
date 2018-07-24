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
int fire[maxn][maxn], people[maxn][maxn];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
queue<tuple<int, int>> fire_q;
queue<tuple<int, int, int>> people_q;
int n, s;
char str[maxn];
tuple<int, int> ans, start;

bool isReach(int t)
{
    int x, y, len, tmpx, tmpy;
    memset(people, 0x3f, sizeof(people));
    while (!people_q.empty())
        people_q.pop();
    people_q.emplace(get<0>(start), get<1>(start), 0);
    people[get<0>(start)][get<1>(start)] = t;
    while (!people_q.empty())
    {
        tie(x, y, len) = people_q.front();
        people_q.pop();
        for (int i = 0; i < 4; i++)
        {
            tmpx = x + dir[i][0], tmpy = y + dir[i][1];
            if (1 <= tmpx && tmpx <= n && 1 <= tmpy && tmpy <= n && people[tmpx][tmpy] == inf)
                if (people[x][y] + !len <= fire[tmpx][tmpy])
                {
                    if (tmpx == get<0>(ans) && tmpy == get<1>(ans))
                    {
                        // for (int i = 1; i <= n; i++)
                        // {
                        //     for (int j = 1; j <= n; j++)
                        //         if (people[i][j] == inf)
                        //             cout << "*   ";
                        //         else
                        //             cout << people[i][j] << "   ";
                        //     cout << endl;
                        // }
                        // cout << endl;
                        return true;
                    }
                    people[tmpx][tmpy] = people[x][y] + !len;
                    if (len >= s -1)
                    {
                        if (people[x][y] + !len < fire[tmpx][tmpy])
                            people_q.emplace(tmpx, tmpy, 0);
                    }
                    else
                        people_q.emplace(tmpx, tmpy, len + 1);
                }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         if (people[i][j] == inf)
    //             cout << "#   ";
    //         else
    //             cout << people[i][j] << "   ";
    //     cout << endl;
    // }
    // cout << endl;
    return false;
}

int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    cin >> n >> s;
    memset(fire, 0x3f, sizeof(fire));
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= n; j++)
        {
            if (str[j] == 'H')
                fire_q.emplace(i, j), fire[i][j] = 0;
            else if (str[j] == 'T')
                fire[i][j] = 0;
            else if (str[j] == 'M')
                start = make_tuple(i, j);
            else if (str[j] == 'D')
                ans = make_tuple(i, j);
        }
    }
    int x, y, tmpx, tmpy;
    //计算每个地方狗仔到达的时间
    while (!fire_q.empty())
    {
        tie(x, y) = fire_q.front();
        fire_q.pop();
        for (int i = 0; i < 4; i++)
        {
            tmpx = x + dir[i][0], tmpy = y + dir[i][1];
            if (1 <= tmpx && tmpx <= n && 1 <= tmpy && tmpy <= n && fire[tmpx][tmpy] == inf)
            {
                fire[tmpx][tmpy] = fire[x][y] + 1;
                fire_q.emplace(tmpx, tmpy);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << fire[i][j] << "   ";
    //     cout << endl;
    // // }
    // cout << endl;

    if (!isReach(0))
    {
        printf("-1\n");
        return 0;
    }
    int low = 0, high = maxn * maxn, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (isReach(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("%d\n", high);
    return 0;
}
