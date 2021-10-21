#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  vector<int> dp(n, 1);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }

  // index가 1부터 배열 끝까지 길이가 가장 긴 감소하는 수열의 길이를 dp에 저장
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      // 조건 : 이전 원소가 현재 원소보다 크거나 같을 때,
      // 현재 원소 이전에 길이가 가장 긴 원소의 값에 1을 더한채로 현재 위치 dp에 저장
      if (arr[j] >= arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  // dp의 원소들 중 가장 큰 원소 반환
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}