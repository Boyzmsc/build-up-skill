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

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int solution(int n, vector<Edge> road) {
  int matrix[n][n];
  memset(matrix, 0, sizeof(matrix));
  for (int i = 0; i < road.size(); i++) {
    matrix[road[i].n[0] - 1][road[i].n[1] - 1] = road[i].w;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  pq.push(make_pair(0, 0));
  for (int i = 1; i < n; i++) {
    pq.push(make_pair(i, INF));
  }

  vector<pair<int, int>> rlt(n, make_pair(INF, INF));
  rlt[0].first = 0;
  rlt[0].second = 0;

  bool visited[n] = {
      false,
  };

  while (!pq.empty()) {
    int pos = pq.top().first;
    int key = pq.top().second;
    pq.pop();

    if (visited[pos]) {
      continue;
    }

    visited[pos] = true;

    for (int i = 0; i < n; i++) {
      if (matrix[pos][i] == 0 || visited[i] == true) {
        continue;
      }

      pq.push(make_pair(i, matrix[pos][i] + key));

      if (rlt[i].first > matrix[pos][i] + key) {
        rlt[i].first = matrix[pos][i] + key;
        rlt[i].second = matrix[pos][i];
      }
    }
  }

  int answer = 0;
  for (int i = 1; i < n; i++) {
    answer += rlt[i].second;
  }

  return answer;
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

    printf("%d\n", solution(n, road));
  }
}