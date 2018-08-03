#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
int n;
int data[maxn], start[maxn];
int main()
{
	//	freopen("number10.in","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", data + i);

	int x = data[1];
	int count = 1;
	start[1] = 1;
	for (int i = 2; i <= n; ++i)
		if (x <= data[i])
			x = data[i], start[++count] = i;
	start[++count] = n + 1;

	int ans = 0;
	for (int i = 1; i < count; ++i)
	{
		x = data[start[i]];
		int k = 0;
		for (int j = start[i] + 1; j < start[i + 1]; ++j)
		{
			++k;
			if (x < data[j])
			{
				ans = max(ans, k);
				x = data[j];
				k = 0;
				continue;
			}
			ans = max(ans, k);
			if (data[j] > data[j + 1])
			{
				x = data[j];
				k = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
