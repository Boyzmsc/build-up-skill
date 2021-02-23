#include <bits/stdc++.h>

using namespace std;

int n;
int paper[2187][2187];
int m_one = 0;
int one = 0;
int zero = 0;

bool check(int y, int x, int n)
{
    int check = paper[y][x];

    if (n == 1)
    {
        if (check == 1)
        {
            one++;
            return true;
        }
        else if (check == 0)
        {
            zero++;
            return true;
        }
        else
        {
            m_one++;
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
                if (check != paper[i][j])
                {
                    return false;
                }
            }
        }
    }

    if (check == 1)
    {
        one++;
    }
    else if (check == 0)
    {
        zero++;
    }
    else
    {
        m_one++;
    }

    return true;
}

void count(int y, int x, int n)
{
    if (!check(y, x, n))
    {
        count(y, x, n / 3);
    }
    if (!check(y, x + n, n))
    {
        count(y, x + n, n / 3);
    }
    if (!check(y, x + (n * 2), n))
    {
        count(y, x + (n * 2), n / 3);
    }

    if (!check(y + n, x, n))
    {
        count(y + n, x, n / 3);
    }
    if (!check(y + n, x + n, n))
    {
        count(y + n, x + n, n / 3);
    }
    if (!check(y + n, x + (n * 2), n))
    {
        count(y + n, x + (n * 2), n / 3);
    }

    if (!check(y + (n * 2), x, n))
    {
        count(y + (n * 2), x, n / 3);
    }
    if (!check(y + (n * 2), x + n, n))
    {
        count(y + (n * 2), x + n, n / 3);
    }
    if (!check(y + (n * 2), x + (n * 2), n))
    {
        count(y + (n * 2), x + (n * 2), n / 3);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    if (!check(0, 0, n))
    {
        count(0, 0, n / 3);
    }

    cout << m_one << '\n';
    cout << zero << '\n';
    cout << one << '\n';
}