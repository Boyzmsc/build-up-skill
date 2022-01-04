#include <bits/stdc++.h>
using namespace std;

// [동물의 숲 - 우수 마을 선정]
// 마을 주민 수의 총 합을 최대로
// 우수 마을 끼리 인접해 있을 수 없음
// 우수 마을로 선정되지 못한 마을은 적어도 하나의 우수 마을과 인접해 있어야 함
// 우수 마을의 주민 수의 총 합을 출력
int dp[10001][2];
int village[10001];
bool visited[10001];
vector<vector<int>> adv(10001);

// DFS 이용
void find(int now) {
  visited[now] = true;

  for (int i = 0; i < adv[now].size(); i++) {
    int next = adv[now][i];

    if (visited[next]) {
      continue;
    }
    find(next);

    // dp[now][0] => 일반 마을
    // dp[now][1] => 우수 마을
    dp[now][0] += max(dp[next][0], dp[next][1]);
    dp[now][1] += dp[next][0];
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> village[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adv[u].push_back(v);
    adv[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
    dp[i][1] = village[i];
  }

  find(1);
  cout << max(dp[1][0], dp[1][1]) << endl;
}