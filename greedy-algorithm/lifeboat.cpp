#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> p, int limit) {
  int answer = 0;
  sort(p.begin(), p.end());
  int left = 0;
  int right = p.size() - 1;

  while (left <= right) {
    if (p[left] + p[right] <= limit) {
      answer++;
      left++;
      right--;
    } else {
      answer++;
      right--;
    }
  }
  return answer;
}