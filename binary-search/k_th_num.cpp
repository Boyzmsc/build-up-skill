#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int rlt;

bool check(int mid)
{
  int count = 0;
  for (int i = 1; i <= N; i++)
  {
    count += min(N, mid / i);
  }
  return count >= K;
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
    rlt = mid;
    rlt = binarySearch(start, mid - 1);
  }
  else
  {
    rlt = binarySearch(mid + 1, end);
  }

  return rlt;
}

int main()
{
  scanf("%d", &N);
  scanf("%d", &K);

  printf("%d", binarySearch(1, K));
}