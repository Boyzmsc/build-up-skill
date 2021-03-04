#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000000];
vector<int> v;

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    arr[i] = num;
  }

  v.push_back(0);

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > v.back())
    {
      v.push_back(arr[i]);
    }
    else
    {
      int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
      v[idx] = arr[i];
    }
  }
  printf("%d\n", v.size() - 1);
}