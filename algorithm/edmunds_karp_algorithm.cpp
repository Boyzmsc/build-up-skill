#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int N = 9999;

int capacity[N][N];
int flow[N][N];
// Vertex 갯수
int V;

int networkFlow(int start, int end) {
  memset(flow, 0, sizeof(flow));
  int totalFlow = 0;

  while (true) {
    vector<int> parent(N - 1);
    queue<int> q;

    parent[start] = start;
    q.push(start);

    while (!q.empty() && parent[end] == -1) {
      int here = q.front();
      q.pop();

      for (int there = 0; there < V; ++there) {
        if (capacity[here][there] - flow[here][there] > 0 &&
            parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
      }
    }

    // 증가경로가 없으면 종료
    if (parent[end] == -1) {
      break;
    }

    int amount = INF;

    // 병목간선을 찾음
    for (int p = end; p != start; p = parent[p]) {
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    }

    for (int p = end; p != start; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }

    totalFlow += amount;
  }

  return totalFlow;
}