#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MOD = 1e8 + 7;

struct matrix
{
    LL v[2][2];
    matrix() { memset(v, 0, sizeof(v)); }
    matrix operator*(const matrix &m)
    {
        matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    c.v[i][j] += (v[i][k] * m.v[k][j]) % MOD;
        return c;
    }
};

matrix M, E, ans; //E为单位矩阵,ans为M^(n-2)

void Init() //初始化
{
    for (int i = 0; i < 2; i++)
        E.v[i][i] = 1;
    M.v[0][0] = 2;
    M.v[0][1] = 1;
    M.v[1][0] = 1;
    M.v[1][1] = 0;
}

matrix pow(matrix p, LL k)
{
    matrix tmp = E;
    while (k)
    {
        if (k & 1)
        {
            tmp = tmp * p;
            k--;
        }
        k >>= 1;
        p = p * p;
    }
    return tmp;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("input1.out", "w", stdout);
    ios::sync_with_stdio(false);
    LL n;
    Init();
    while (cin >> n)
    {
        if (n < 0)
            cout << "No" << endl;
        else if (n == 0)
            cout << "1" << endl;
        else if (n == 1)
            cout << "2" << endl;
        else if (n == 2)
            cout << "9" << endl;
        else
        {
            ans = pow(M, n - 2);
            LL an = (ans.v[0][0] * 3 + ans.v[0][1] * 1) % MOD;
            cout << an << "@" << endl;
            if (n & 1)
                cout << ((an * an) % MOD + 1) % MOD << endl;
            else
                cout << (an * an) % MOD << endl;
        }
    }
    return 0;
}