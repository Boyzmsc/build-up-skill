#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void hanoi(vector<int> &arr, int n, ll idx, int start, int end) {
  ll mid = 1ll << (n - 1);

  if (n == 0)
    return;

  if (idx < mid) {
    arr[n - 1] = start;
    hanoi(arr, n - 1, idx, start, 6 - start - end);
  } else {
    arr[n - 1] = end;
    hanoi(arr, n - 1, idx - mid, 6 - start - end, end);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    ll idx;
    cin >> n >> idx;

    vector<int> before, after;

    for (int j = 0; j < n; j++) {
      before.push_back(1);
      after.push_back(1);
    }

    hanoi(before, n, idx - 1, 1, 3);
    hanoi(after, n, idx, 1, 3);

    for (int j = 0; j < n; j++) {
      if (before[j] != after[j]) {
        printf("%d %d\n", before[j], after[j]);
        break;
      }
    }
  }
}
