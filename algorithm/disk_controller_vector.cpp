#include <bits/stdc++.h>
using namespace std;

// 소요 시간을 기준으로 오름차순으로 정렬하기 위한 비교 함수
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}

int solution(vector<vector<int>> jobs) {
  // 각 작업의 요청 ~ 종료까지의 시간
  int total = 0;
  // 현재 시간
  int time = 0;
  // Vector에 들어간 작업 수
  int idx = 0;

  vector<pair<int, int>> v;

  // 요청 시간 오름차순으로 정렬
  sort(jobs.begin(), jobs.end());

  // 예정된 작업이 모두 수행될 때까지 반복
  while (idx < jobs.size() || !v.empty()) {
    // 요청 시간이 현재 시간보다 작아야 함
    if (idx < jobs.size() && jobs[idx][0] <= time) {
      v.push_back(make_pair(jobs[idx][0], jobs[idx][1]));
      idx++;
      continue;
    }

    // 가장 작은 소요 시간 탐색을 위해
    // 소요 시간 오름차순으로 정렬
    sort(v.begin(), v.end(), cmp);

    // 수행 작업이 존재할 시
    if (!v.empty()) {
      // 현재시간 갱신
      time += v[0].second;
      // 총 작업 시간 갱신
      total += time - v[0].first;
      // 끝난 작업은 삭제
      v.erase(v.begin());
    }
    // 수행 작업이 존재하지 않을 시
    else {
      // 현재 시간을 다음 작업의 요청 시간으로 설정
      time = jobs[idx][0];
    }
  }

  // 총 작업의 요청부터 종료까지 시간의 평균
  return total / jobs.size();
}