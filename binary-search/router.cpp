#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int C;
ll h[200000];
int rlt;

bool check(ll dist)
{
  int check = 1;
  ll l_value = h[0];
  for (int i = 1; i < N; i++)
  {
    if (h[i] - l_value >= dist)
    {
      check++;
      l_value = h[i];
    }
  }
  return check >= C;
}

int binarySearch(int start, int end)
{
  int mid = (start + end) / 2;

  if (start > end)
  {
    return rlt;
  }

  if (check(mid))
  {
    rlt = max(mid, binarySearch(mid + 1, end));
  }
  else
  {
    binarySearch(start, mid - 1);
  }

  return rlt;
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &C);

  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &h[i]);
  }

  sort(h, h + N);

  printf("%d\n", binarySearch(1, 1000000000));
}