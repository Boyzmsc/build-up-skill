#include <bits/stdc++.h>
using namespace std;

int cards[500000];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &cards[i]);
  }

  sort(cards, cards + n);

  int f;
  scanf("%d", &f);

  for (int i = 0; i < f; i++)
  {
    int toFind;
    scanf("%d", &toFind);
    int ans = upper_bound(cards, cards + n, toFind) - lower_bound(cards, cards + n, toFind);
    printf("%d ", ans);
  }

  return 0;
}