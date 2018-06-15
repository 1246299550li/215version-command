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
#include <iterator>
const long long llf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
using namespace std;
//字典树
int tree_num, ans;
char data[maxn];
struct node
{
    int num;
    int child[2];
} tree[10000010];
void inser(char *str)
{
    int post = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int m = str[i] - '0';
        if (tree[post].child[m] == -1)//如果子树为空则创建子树
        {
            tree_num++;
            tree[tree_num].num = 0;
            for (int i = 0; i < 2; i++)
                tree[tree_num].child[i] = -1;
            tree[post].child[m] = tree_num;
        }
        post = tree[post].child[m];
        tree[post].num++;
        ans = max(ans, tree[post].num * (i + 1));
    }
}
int main()
{
    // freopen("input.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        tree_num = 0;
        memset(tree[0].child, -1, sizeof(tree[0].child));
        scanf("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", data);
            inser(data);
        }
        cout << ans << endl;
    }
    return 0;
}