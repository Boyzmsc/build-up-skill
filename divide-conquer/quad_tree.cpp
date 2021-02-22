#include <bits/stdc++.h>

using namespace std;

int n;
int tree[64][64];

bool check(int y, int x, int n)
{
    int check = tree[y][x];

    if (n == 1)
    {
        if (check == 0)
        {
            cout << 0;
            return true;
        }
        else
        {
            cout << 1;
            return true;
        }
    }

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (i == y && j == x)
            {
                continue;
            }
            else
            {
                if (check != tree[i][j])
                {
                    return false;
                }
            }
        }
    }

    if (check == 0)
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }

    return true;
}

void zip(int y, int x, int n)
{
    if (!check(y, x, n))
    {
        cout << "(";
        zip(y, x, n / 2);
        cout << ")";
    }
    if (!check(y, x + n, n))
    {
        cout << "(";
        zip(y, x + n, n / 2);
        cout << ")";
    }
    if (!check(y + n, x, n))
    {
        cout << "(";
        zip(y + n, x, n / 2);
        cout << ")";
    }
    if (!check(y + n, x + n, n))
    {
        cout << "(";
        zip(y + n, x + n, n / 2);
        cout << ")";
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &tree[i][j]);
        }
    }

    if (!check(0, 0, n))
    {
        cout << "(";
        zip(0, 0, n / 2);
        cout << ")";
    }
}