#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
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
const int maxn = 100005;
using namespace std;
struct t
{
	int l;
	int r;
	long long sum;
} tree[maxn << 2];
long long v;
void build(int pos, int l, int r)
{
	tree[pos].l = l, tree[pos].r = r;
	if (l == r)
	{
		tree[pos].sum = v;
		return;
	}
	int mid = (l + r) >> 1;
	build(pos << 1, l, mid);
	build(pos << 1 | 1, mid + 1, r);
	tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
}
long long inquiry(int pos, int l, int r)
{
	if (tree[pos].l == l && tree[pos].r == r)
		return tree[pos].sum;
	int mid = (tree[pos].l + tree[pos].r) >> 1;
	if (l > mid)
		return inquiry(pos << 1 | 1, l, r);
	else if (r <= mid)
		return inquiry(pos << 1, l, r);
	else
		return inquiry(pos << 1, l, mid) + inquiry(pos << 1 | 1, mid + 1, r);
}
void adds(int pos, int l, int r, int value)
{
	if (l == r)
	{
		tree[pos].sum += value;
		return;
	}
	int mid = (l + r) >> 1;
	adds(pos << 1, l, mid, value);
	adds(pos << 1 | 1, mid + 1, r, value);
	tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
}
void changes(int pos, int l, int r, int value)
{
	if (l == r)
	{
		tree[pos].sum = value;
		return;
	}
	int mid = (l + r) >> 1;
	changes(pos << 1, l, mid, value);
	changes(pos << 1 | 1, mid + 1, r, value);
	tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
}
int main()
{
	freopen("input.in", "r", stdin);
	freopen("input.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m >> v)
	{
		memset(tree, 0, sizeof(tree));
		build(1, 1, n);
		for (int i = 1; i <= m; i++)
		{
			int tmp, l, r, vv;
			cin >> tmp;
			if (tmp == 2)
			{
				cin >> l >> r;
				cout << inquiry(1, l, r) << endl;
			}
			else
			{
				cin >> l >> r >> vv;
				if (tmp == 0)
					adds(1, l, r, vv);
				else
					changes(1, l, r, vv);
			}
		}
	}
	return 0;
}
