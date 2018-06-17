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
const int maxn = 105;
using namespace std;
//桶排序
int l[maxn], r[maxn];
int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("input1.out", "w", stdout);
    int n;
    int a, b;
    while (~scanf("%d", &n))
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            l[a]++;
            r[b]++;
            int max1 = -1;
            int kl = 0;
            int kr = 100;
            int cntl = l[kl];
            int cntr = r[kr];
            while (kl <= 100 && kr >= 0)
            {
                if (cntl && cntr)
                max1 = max(kl + kr, max1);
                if (cntl == cntr)
                {
                    kl++;
                    kr--;
                    cntl = l[kl];
                    cntr = r[kr];
                    continue;
                }
                else if (cntl > cntr)
                {
                    kr--;
                    cntl -= cntr;
                    cntr = r[kr];
                }
                else if (cntr > cntl)
                {
                    kl++;
                    cntr -= cntl;
                    cntl = l[kl];
                }
            }
            printf("%d\n", max1);
        }
        printf("\n");
    }

    return 0;
}

