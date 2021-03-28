#include <bits/stdc++.h>

using namespace std;

int n;
int paper[128][128];
int white = 0;
int blue = 0;

bool check(int y, int x, int n)
{
  int check = paper[y][x];

  if (n == 1)
  {
    if (check == 0)
    {
      white++;
      return true;
    }
    else
    {
      blue++;
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

  if (check == 0)
  {
    white++;
  }
  else
  {
    blue++;
  }

  return true;
}

void fold(int y, int x, int n)
{
  if (!check(y, x, n))
  {
    fold(y, x, n / 2);
  }
  if (!check(y, x + n, n))
  {
    fold(y, x + n, n / 2);
  }
  if (!check(y + n, x, n))
  {
    fold(y + n, x, n / 2);
  }
  if (!check(y + n, x + n, n))
  {
    fold(y + n, x + n, n / 2);
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
    fold(0, 0, n / 2);
  }

  cout << white << '\n';
  cout << blue << '\n';
}