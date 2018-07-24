#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f, maxn = 100005;
char s[maxn];
int Rank, Star;
void up(int v)
{
    Star += v;
    if (Rank >= 21 && Rank <= 25 && Star > 2)
        Rank--, Star -= 2;
    else if (Rank >= 16 && Rank <= 20 && Star > 3)
        Rank--, Star -= 3;
    else if (Rank >= 11 && Rank <= 15 && Star > 4)
        Rank--, Star -= 4;
    else if (Rank >= 1 && Rank <= 10 && Star > 5)
        Rank--, Star -= 5;
}
void down()
{
    if (Rank > 20)
        return;
    if (Star)
    {
        Star--;
        return;
    }
    if (Rank < 20)
    {
        Rank++;
        if (Rank >= 16 && Rank <= 20)
            Star = 2;
        else if (Rank >= 11 && Rank <= 15)
            Star = 3;
        else if (Rank >= 1 && Rank <= 10)
            Star = 4;
    }
}
int main()
{
    freopen("input.in", "r", stdin);
	freopen("input1.out", "w", stdout);
    while (~scanf("%s", s))
    {
        int n = strlen(s);
        Rank = 25, Star = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (Rank == 0)
                break;
            if (s[i] == 'L')
                down(), num = 0;
            else if (s[i] == 'W')
            {
                num++;
                if (Rank >= 6 && num >= 3)
                    up(2);
                else
                    up(1);
            }
            //printf("rank=%d star=%d\n",rank,star);
        }
        if (Rank)
            printf("%d\n", Rank);
        else
            printf("Legend\n");
    }
    return 0;
}