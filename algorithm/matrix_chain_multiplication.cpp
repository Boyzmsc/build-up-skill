#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  vector<int> p;

  cin >> n;
  for (int i = 0; i <= n; i++) {
    int d;
    cin >> d;
    p.push_back(d);
  }

  vector<vector<ll>> m(n + 1, vector<ll>(n + 1, 0));

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = LLONG_MAX;
      for (int k = i; k <= j - 1; k++) {
        ll q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
        }
      }
    }
  }

  cout << m[1][n];
  return 0;
}