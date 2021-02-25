#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll N;
matrix A = {{1, 1}, {1, 0}};
ll mod = 1000000007LL;

matrix multiple(const matrix &x, const matrix &y)
{
    matrix res(x.size(), vector<ll>(y[0].size(), 0));

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y[0].size(); j++)
        {
            for (int l = 0; l < y.size(); l++)
            {
                res[i][j] += (x[i][l] * y[l][j]) % mod;
            }
            res[i][j] %= mod;
        }
    }
    return res;
}

matrix solve(ll s)
{
    matrix tmp;

    if (s == 1)
    {
        return A;
    }

    if (s % 2 == 0)
    {
        tmp = solve(s / 2);
        return multiple(tmp, tmp);
    }
    else
    {
        tmp = solve(s - 1);
        return multiple(A, tmp);
    }
}

int main()
{
    cin >> N;
    matrix rlt = solve(N);
    cout << rlt[1][0] << '\n';
}