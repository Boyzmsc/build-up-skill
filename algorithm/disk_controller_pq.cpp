#include <bits/stdc++.h>
using namespace std;

// 구조체 안에 operator()를 재정의 하여
// vector의 1번째 원소(소요 시간)기준 오름차순으로 정렬하도록 설정
// a(부모)가 b(자식)보다 크면 교환할 것
struct cmp {
  bool operator()(vector<int> &a, vector<int> &b) { return a[1] > b[1]; }
};

int solution(vector<vector<int>> jobs) {
  // 작업이 요청되는 시점 순으로 정렬
  sort(jobs.begin(), jobs.end());
  // 소요 시간을 기준 오름차순으로 정렬된 queue
  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
  // 각 작업의 요청 ~ 종료까지의 시간
  int answer = 0;
  // 현재 시간
  int time = 0;
  // heap에 들어간 작업 수
  int task = 0;

  // 예정된 작업이 모두 heap에 담을 때까지 반복
  while (task < jobs.size() || !pq.empty()) {
    // 요청 시간이 현재 시간보다 작고, 할 작업이 남아있을 경우
    if (task < jobs.size() && time >= jobs[task][0]) {
      // pq에 삽입
      pq.push(jobs[task++]);
      continue;
    }
    // 수행할 작업이 남아있는 경우
    if (!pq.empty()) {
      // 현재 시간 업데이트
      time += pq.top()[1];
      // 총 작업 시간 업데이트
      answer += time - pq.top()[0];
      // 끝난 작업은 삭제
      pq.pop();
    }
    // 수행할 작업이 없는 경우
    else
      // 다음 작업이 시작될 시간으로 이동
      time = jobs[task][0];
  }
  // 총 작업의 요청부터 종료까지 시간의 평균
  return answer / jobs.size();
}