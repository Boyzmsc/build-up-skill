#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &v) {
  int left = 0;
  int right = v.size() - 1;
  int max_capacity = min(v[left], v[right]) * (right - left);
  while (left < right) {
    // 길이를 비교하며 공간을 막대를 줄여가며 최소화
    if (v[left] >= v[right])
      right--;
    else
      left++;

    int cap = min(v[left], v[right]) * (right - left);

    // 최대 용량 저장
    max_capacity = max(max_capacity, cap);
  }
  return max_capacity;
}