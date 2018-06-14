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
#include <iomanip>
#include <fstream>
#include <climits>
const long long llf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;
//字典树
long long data[maxn];
struct Trie
{
    int son[maxn * 13][3], cnt;
    int pos, flag;
    long long res, ans;
    void init()
    {
        memset(son, 0, sizeof(son));
        cnt = 0, ans = -1;
    }
    void insert(long long num)
    {
        pos = 0;
        for (int i = 31; i >= 0; i--)
        {
            flag = (num >> i) & 1;
            if (!son[pos][flag])
                son[pos][flag] = ++cnt;
            pos = son[pos][flag];
        }
    }
    long long find(int num)
    {
        pos = 0, res = 0;
        for (int i = 31; i >= 0; i--)
        {
            flag = !((num >> i) & 1); //取反查找
            res <<= 1;
            if (son[pos][flag])
                pos = son[pos][flag], res++;
            else
                pos = son[pos][!flag];
        }
        return res;
    }
} trie;
int main()
{
    // freopen("input.in", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        trie.init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &data[i]);
            trie.insert(data[i]);
            trie.ans = max(trie.ans, trie.find(data[i]));
        }
        printf("%lld\n", trie.ans);
    }
    return 0;
}
