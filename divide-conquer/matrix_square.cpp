#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;

ll n, b;

matrix multiple(const matrix &x, const matrix &y)
{
    matrix res(n, vector<int>(n, 0));
    int entry;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            entry = 0;
            for (int l = 0; l < n; l++)
            {
                entry += x[i][l] * y[l][j];
            }
            res[i][j] = entry % 1000;
        }
    }
    return res;
}

matrix solve(matrix m, ll s)
{
    matrix tmp(n, vector<int>(n));

    if (s == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                tmp[i][j] = m[i][j] % 1000;
            }
        }
        return tmp;
    }

    if (s % 2 == 0)
    {
        tmp = solve(m, s / 2);
        return multiple(tmp, tmp);
    }
    else
    {
        tmp = solve(m, s - 1);
        return multiple(m, tmp);
    }
}

void printMatrix(matrix m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> b;
    matrix m(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    printMatrix(solve(m, b));

    return 0;
}
