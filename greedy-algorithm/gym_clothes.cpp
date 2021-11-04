#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;
  vector<int> v(n + 1, 1);

  for (int i = 0; i < lost.size(); i++) {
    v[lost[i]] -= 1;
  }

  for (int i = 0; i < reserve.size(); i++) {
    v[reserve[i]] += 1;
  }

  for (int i = 1; i < v.size(); i++) {
    if (i == v.size() - 1 && v[i] == 2 && v[i - 1] == 0) {
      v[i - 1] = 1;
      v[i] = 1;
      continue;
    }
    if (v[i - 1] == 0 && v[i] == 2) {
      v[i - 1] = 1;
      v[i] = 1;
    } else if (v[i] == 2 && v[i + 1] == 0) {
      v[i] = 1;
      v[i + 1] = 1;
    }
  }

  for (int i = 1; i < v.size(); i++) {
    if (v[i] == 2) {
      v[i] = 1;
    }
    answer += v[i];
  }

  return answer;
}