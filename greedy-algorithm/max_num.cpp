#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
  string answer = "";
  vector<int> v;

  for (int i = 0; i < number.length(); i++) {
    v.push_back(number[i] - '0');
  }

  int idx = 0;
  for (int i = 0; i < v.size() - k; i++) {
    int max = -1;
    for (int j = idx; j <= i + k; j++) {
      if (max < v[j]) {
        max = v[j];
        idx = j;
      }
    }
    v[idx] = -1;
    answer += to_string(max);
  }

  return answer;
}