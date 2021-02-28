#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int m;
ll trees[1000000];

bool check(ll mid)
{
  ll check = 0;
  for (int i = 0; i < n; i++)
  {
    if (trees[i] - mid >= 0)
    {
      check += trees[i] - mid;
    }
  }
  return (check >= m);
}

ll binarySearch(ll start, ll end)
{
  ll mid = (start + end) / 2;
  ll rlt;

  if (start > end)
  {
    return 0;
  }

  if (check(mid))
  {
    rlt = max(binarySearch(mid + 1, end), mid);
  }
  else
  {
    rlt = binarySearch(start, mid - 1);
  }

  return rlt;
}

int main()
{
  scanf("%d", &n);
  scanf("%d", &m);

  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &trees[i]);
  }

  ll end = LLONG_MAX;

  printf("%lld\n", binarySearch(0, end));
}