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
    vector<int> dp(value+1,INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < num; i++) {
      int coin;
      scanf("%d", &coin);
      coins.push_back(coin);
    }

    // 2차원 배열을 이용한 DP
    for (int i = 0; i< coins.size(); i++){
        for (int j = coins[i]; j <= value; j++) {
          dp[j] = min(dp[j], dp[j-coins[i]]+1);
        }
    }
    
    cout << dp[value] << endl;
  }
}