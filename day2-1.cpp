#include <stdio.h>
#include <algorithm>
using namespace std;
int a[501], b[501], m[250001], c[501], flag;
int main()
{
    int i, j, k, n1, n2, n3, n4, ci = 0;
    while (scanf("%d%d%d", &n1, &n2, &n3) != EOF)
    {
        ci++;
        for (i = 0; i < n1; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n2; i++)
            scanf("%d", &b[i]);
        for (i = 0; i < n3; i++)
            scanf("%d", &c[i]);
        n4 = 0;
        for (i = 0; i < n1; i++)
            for (j = 0; j < n2; j++)
                m[n4++] = a[i] + b[j];
        sort(m, m + n4);
        int N;
        scanf("%d", &N);
        printf("Case %d:\n", ci);
        while (N--)
        {
            flag = 0;
            scanf("%d", &k);
            for (i = 0; i < n3; i++)
            {
                if (binary_search(m, m + n4, k - c[i]))
                    flag = 1;
                if (flag == 1)
                    break;
            }
            if (flag == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
