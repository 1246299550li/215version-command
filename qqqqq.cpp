//author QJS;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
struct point
{
	int x, y, step;
} st;
queue <point> q;
int vis[200000];//标记数组，判断这个点是否走过。
int n, m;
int flat;
int bfs()
{
	while (!q.empty())//每一次都将队列里面的数清空
	{
		q.pop();
	}
 
	memset(vis, 0, sizeof(vis));
	vis[st.x] = 1;//牧场主开始的位置标记，代表不会走回来
	q.push(st);
	while (!q.empty())//当队列中还有数存在是时候，一直循环
	{
 
		point now = q.front();
		if(now.x==m)
			return now.step;//当一开始，牧场主和牛的位置一样的时候，就直接返回。这个不要忘记
		q.pop();
		for (int j = 0; j < 3; j++)//三种情况的循环
		{
			point next = now;
 
			if (j == 0)
			{
				next.x = next.x + 1;
			}
			else if (j == 1)
			{
				next.x = next.x - 1;
			}
			else if (j == 2)
			{
				next.x = next.x * 2;
			}
			++next.step;
			if (next.x == m)
			{
				return next.step;
			}
			if (next.x >= 0 && next.x <= 200000 && !vis[next.x])//判断是否越界
			{
				vis[next.x] = 1;
				q.push(next);
			}
		}
	}
return 0;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("input1.out", "w", stdout);
	while (~scanf("%d %d", &n, &m))
	{
		st.x = n;
		st.step=0;
		printf("%d\n", bfs());
	}
 
	return 0;
}
