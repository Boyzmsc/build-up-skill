#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool cut[1001];

int optimal(int start, int end) {
  int mem = dp[start][end];
  if (mem != INT_MAX) {
    return mem;
  }

  int minCost = INT_MAX;
  for (int i = start + 1; i < end; i++) {
    if (cut[i]) {
      int len = end - start;
      int cost = len + optimal(start, i) + optimal(i, end);

      minCost = min(cost, minCost);
    }
  }

  if (minCost == INT_MAX) {
    minCost = 0;
  }

  dp[start][end] = minCost;

  return minCost;
}

int main() {
  int test_case;
  scanf("%d", &test_case);

  while (test_case--) {
    int len, cnt;
    scanf("%d %d", &len, &cnt);

    for (int i = 0; i <= 1000; i++) {
      cut[i] = false;
      for (int j = 0; j <= 1000; j++) {
        dp[i][j] = INT_MAX;
      }
    }

    for (int i = 0; i < cnt; i++) {
      int n;
      scanf("%d", &n);
      cut[n] = true;
    }

    printf("%d\n", optimal(0, len));
  }
}