#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <climits>
const long long llf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1000005;
using namespace std;

int pos, ans;
struct node
{
    int num;
    int child[2];
} tree[10000010];

int add()
{
    pos++;
    tree[pos].num = 0;
    for (int i = 0; i < 2; i++)
    {
        tree[pos].child[i] = -1;
    }
    return pos;
}

int inser(char *str)
{
    int post = 0;
    int tmp = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int m = str[i] - '0';
        if (tree[post].child[m] == -1)
        {
            if (tmp == 0)
                tmp = i + 1;
            tree[post].child[m] = add();
        }

        post = tree[post].child[m];
        tree[post].num++;
        ans = max(ans, tree[post].num * (i + 1));
    }
    if (!tmp)
        tmp = len;
    return tmp;
}

char arr[maxn];
int main()
{
    freopen("input.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        pos = 0;
        memset(tree[0].child, -1, sizeof(tree[0].child));
        scanf("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", arr);
            int k = inser(arr);
        }
        cout << ans << endl;
    }
    return 0;
}