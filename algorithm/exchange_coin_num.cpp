#include <bits/stdc++.h>
using namespace std;

int main() {
  int test_case;
  scanf("%d", &test_case);
  while (test_case--) {
    int value, num;
    int rlt = 0;
    scanf("%d", &value);
    scanf("%d", &num);

    vector<int> coins;
    int dp[num + 1][value + 1];

    dp[0][0] = 1;
    for (int i = 1; i < value + 1; i++) {
      dp[0][i] = 0;
    }

    for (int i = 0; i < num; i++) {
      int coin;
      scanf("%d", &coin);
      coins.push_back(coin);
    }

    // 2차원 배열을 이용한 DP
    for (int i = 1; i < num + 1; i++) {
      for (int j = 0; j < value + 1; j++) {
        if (0 <= j && j < coins[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else if (coins[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        }
      }
    }

    cout << dp[num][value] << endl;
  }
}