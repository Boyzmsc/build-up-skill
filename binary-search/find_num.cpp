#include <bits/stdc++.h>

using namespace std;

int nums[100000];

bool binarySearch(int start, int end, int f)
{
  int mid = (start + end) / 2;
  bool rlt;

  if (start > end)
  {
    return false;
  }

  if (nums[mid] == f)
  {
    return true;
  }
  else if (nums[mid] > f)
  {
    rlt = binarySearch(start, mid - 1, f);
  }
  else if (nums[mid] < f)
  {
    rlt = binarySearch(mid + 1, end, f);
  }

  return rlt;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  sort(nums, nums + n);

  int f;
  scanf("%d", &f);

  for (int i = 0; i < f; i++)
  {
    int toFind;
    scanf("%d", &toFind);
    printf("%d\n", (int)binarySearch(0, n - 1, toFind));
  }

  return 0;
}