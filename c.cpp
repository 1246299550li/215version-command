#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int nextt[10010], T[10010];
int S[1000100];
int n, m, ans;
void get_next()
{
    int i = 1, j = 0;
    nextt[1] = 0; 
    while (i < m)
    {
        if (j == 0 || T[i] == T[j]) 
        {
            ++i;
            ++j;
            nextt[i] = j;
        }
        else
            j = nextt[j]; 
    }
}
void kmp()
{
    int i = 1, j = 1;
    while (i <= n && j <= m)
    {
        if (j == 0 || S[i] == T[j])
        {
            ++i, ++j;
        }
        else
            j = nextt[j];
    }
    if (j > m)
        printf("%d\n", i - m);
    else
        printf("-1\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        int i, j;
        for (i = 1; i <= n; i++)
            scanf("%d", &S[i]);
        for (i = 1; i <= m; i++)
            scanf("%d", &T[i]);
        S[0] = T[0] = -1;
        get_next();
        kmp();
    }
}