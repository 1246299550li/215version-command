#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
//#include <ctime>

const int N = 1e6 + 5;

int n, ans, a[N], last[N], next[N];
int del[N];
std::queue<int> q, s;

inline int getint()
{
	char c;
	while ((c = getchar()) < '0' || c > '9')
		;
	int a = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		a = a * 10 + c - '0';
	return a;
}

int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	n = getint();
	for (int i = 1; i <= n; i++)
	{
		a[i] = getint();
		last[i] = i - 1;
		next[i] = i + 1;
	}
	next[n] = 0;
	last[0] = n;
	next[0] = 1;
	del[0] = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] < a[i - 1])
			del[i] = 1, q.push(i);
	while (!q.empty())
	{
		ans++;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (last[x] && del[last[x]] != ans && next[x] && del[next[x]] != ans && a[next[x]] < a[last[x]])
			{
				s.push(next[x]);
				del[next[x]] = ans + 1;
			}
			next[last[x]] = next[x];
			last[next[x]] = last[x];
		}
		q = s;
		while (!s.empty())
			s.pop();
		//	for(int i=next[0];i;i=next[i]) printf(" %d",a[i]); puts("");
	}
	printf("%d\n", ans);
	//	printf("%d\n",clock());
	scanf("\n");
	return 0;
}
