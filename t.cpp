#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
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
typedef long long ll;
typedef pair<int, int> P;
int mod_pow(int a, int b, int c)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ll)ans * a % c;
        a = (ll)a * a % c;
        b >>= 1;
    }
    return ans;
}
int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}
int Solve(int n, int m)
{
    if (m == 1)
        return 0;
    if (n == 1)
        return 1 % m;
    if (n == 2)
        return 2 % m;
    if (n == 3)
        return 9 % m;
    if (n == 4)
        return (1 << 18) % m;
    int t = phi(m);
    int ans = (ll)mod_pow(n, phi(m), m) * mod_pow(n, Solve(n - 1, phi(m)), m) % m;
    return ans;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
        printf("%d\n", Solve(n, m));
    return 0;
}