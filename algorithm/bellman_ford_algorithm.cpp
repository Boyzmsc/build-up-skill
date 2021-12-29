#include <bits/stdc++.h>
using namespace std;

int INF = 9999;

class Edge {
public:
  int n[2];
  int w;

  Edge(int u, int v, int w) {
    this->n[0] = u;
    this->n[1] = v;
    this->w = w;
  }
};

bool solution(int n, vector<Edge> road) {
  // Key : Pred
  vector<pair<int, int>> vertex(n + 1, make_pair(INF, INF));
  vertex[1].first = 0;
  vertex[1].second = 1;

  int matrix[n][n];
  memset(matrix, 0, sizeof(matrix));
  for (int i = 0; i < road.size(); i++) {
    matrix[road[i].n[0] - 1][road[i].n[1] - 1] = road[i].w;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < road.size(); j++) {
      if (vertex[road[j].n[1]].first > vertex[road[j].n[0]].first + road[j].w) {
        vertex[road[j].n[1]].first = vertex[road[j].n[0]].first + road[j].w;
        vertex[road[j].n[1]].second = road[j].n[0];
      }
    }
  }

  // Print
  for (int i = 1; i < vertex.size(); i++) {
    cout << "[" << i << "] " << vertex[i].first << " " << vertex[i].second << endl;
  }

  // Negative Cycle Check
  for (int i = 0; i < road.size(); i++) {
    if (vertex[road[i].n[1]].first > vertex[road[i].n[0]].first + road[i].w) {
      return false;
    }
  }
  return true;
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    vector<Edge> road;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int k, m;
      scanf("%d %d", &k, &m);
      for (int j = 0; j < m; j++) {
        int v, w;
        scanf("%d %d", &v, &w);
        road.push_back(Edge(k, v, w));
      }
    }

    cout << solution(n, road) << endl;
  }
}