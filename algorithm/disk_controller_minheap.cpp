#include <algorithm>
#include <vector>
using namespace std;

// jobs[i][1](수행시간)의 subtree들이 Max Heap property를 만족하도록 하는 연산
void heapify(vector<vector<int>> &jobs, int index, int size) {
  // index가 0부터 시작한다는 가정
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int largest = index;

  // 왼쪽 자식이 자신보다 큰 경우
  if (left < size && jobs[left][1] >= jobs[largest][1])
    largest = left;

  // 오른쪽 자식이 자신보다 큰 경우
  if (right < size && jobs[right][1] >= jobs[largest][1])
    largest = right;

  // 위의 두 경우(자신이 자식보다 작은 경우)
  if (largest != index) {
    // 노드 교환
    swap(jobs[index], jobs[largest]);
    // Max Heap property를 만족하도록 재연산
    heapify(jobs, largest, size);
  }
}

// jobs를 Heap으로 만드는 연산
void build(vector<vector<int>> &jobs) {
  int size = jobs.size();
  // 중간 노드부터 항상 자식 노드가 존재하므로 중간부터 반복문 실행
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(jobs, i, size);
  }
}

// Heap 정렬 연산
vector<vector<int>> heap_sort(vector<vector<int>> &jobs) {
  // 들어온 jobs vector을 heap으로 만듦
  build(jobs);
  for (int i = jobs.size() - 1; i >= 1; i--) {
    // 마지막 노드와 최상위 노드 교환
    swap(jobs[0], jobs[i]);
    // Max Heap property를 만족하도록 재연산
    heapify(jobs, 0, i);
  }
  return jobs;
}

int solution(vector<vector<int>> jobs) {
  // 작업이 요청되는 시점 순으로 정렬
  sort(jobs.begin(), jobs.end());
  // 소요 시간을 기준 오름차순으로 정렬된 vector
  vector<vector<int>> heap;
  // 각 작업의 요청 ~ 종료까지의 시간
  int answer = 0;
  // 현재 시간
  int time = 0;
  // heap에 들어간 작업 수
  int task = 0;

  // 예정된 작업이 모두 heap에 담을 때까지 반복
  while (task < jobs.size() || !heap.empty()) {
    // 요청 시간이 현재 시간보다 작고, 할 작업이 남아있을 경우
    if (task < jobs.size() && time >= jobs[task][0]) {
      // heap에 삽입
      heap.push_back(jobs[task++]);
      // 다시 정렬
      heap = heap_sort(heap);
      continue;
    }
    // 수행할 작업이 남아있는 경우
    if (!heap.empty()) {
      // 현재 시간 업데이트
      time += heap[0][1];
      // 총 작업 시간 업데이트
      answer += time - heap[0][0];
      // 끝난 작업은 삭제
      heap.erase(heap.begin());
    }
    // 수행할 작업이 없는 경우
    else
      // 다음 작업이 시작될 시간으로 이동
      time = jobs[task][0];
  }
  // 총 작업의 요청부터 종료까지 시간의 평균
  return answer / jobs.size();
}