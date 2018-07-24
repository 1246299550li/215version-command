//二分&&狗仔预处理&&BFS
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 800;
const int maxs = 1000;
const int inf = 99999;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int n, s;
char c[maxn + 10][maxn + 10];
int w[maxn + 10][maxn + 10], vst[maxn + 10][maxn + 10];
int sx, sy, ex, ey;
struct step
{
	int x, y;
	int et, tt;
};
queue<step> q;

void prework()
{
	step now, tem;
	int i;

	while (!q.empty())
	{
		now = q.front();
		q.pop();
		w[now.x][now.y] = now.et;
		for (i = 0; i < 4; ++i)
		{
			tem.x = now.x + dx[i];
			tem.y = now.y + dy[i];
			if (c[tem.x][tem.y] == 'G' && !vst[tem.x][tem.y])
			{
				tem.et = now.et + 1;
				vst[tem.x][tem.y] = 1;
				q.push(tem);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (w[i][j] == inf)
				cout << "*   ";
			else
				cout << w[i][j] << "   ";
		cout << endl;
	}
	cout << endl;
}

bool gohome(int t)
{
	int i, tt;
	step now, tem;

	memset(vst, 0, sizeof(vst));
	while (!q.empty())
		q.pop();
	now.x = sx;
	now.y = sy;
	now.et = now.tt = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (i = 0; i < 4; ++i)
		{
			tem.x = now.x + dx[i];
			tem.y = now.y + dy[i];
			tem.et = now.et + 1;
			tem.tt = now.tt;
			if (tem.et == s)
			{
				tem.et = 0;
				tem.tt = now.tt + 1;
			}
			if (c[tem.x][tem.y] == 'G' && !vst[tem.x][tem.y] && (t + tem.tt) < w[tem.x][tem.y])
			{
				vst[tem.x][tem.y] = 1;
				q.push(tem);
			}
			else if (c[tem.x][tem.y] == 'D')
			{
				return true;
			}
		}
	}

	return false;
}

void binary()
{
	int left = 0, right = maxn * maxn, mid;

	if (!gohome(left))
	{
		printf("-1\n");
		return;
	}
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (gohome(mid))
		{
			left = mid + 1; //printf("mid:%d r:%d\n",mid,right);
		}
		else
		{
			right = mid - 1;
		}
	}
	printf("%d\n", right);
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("input1.out", "w", stdout);
	int i, j;
	step tems;

	scanf("%d%d", &n, &s);
	memset(vst, 0, sizeof(vst));
	for (i = 0; i <= n + 1; ++i)
	{
		c[0][i] = c[i][0] = c[n + 1][i] = c[i][n + 1] = 'T';
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf(" %c", &c[i][j]);
			w[i][j] = inf;
			switch (c[i][j])
			{
			case 'H':
				tems.x = i;
				tems.y = j;
				tems.et = 0;
				q.push(tems);
				break;
			case 'M':
				sx = i;
				sy = j;
				break;
			case 'D':
				ex = i;
				ey = j;
				break;
			default:
				break;
			}
		}
	}
	prework();
	binary();

	return 0;
}
