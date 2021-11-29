#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int n[2];
  int w;

  Edge(int u, int v, int w) {
    this->n[0] = u;
    this->n[1] = v;
    this->w = w;
  }

  bool operator<(Edge &e) { return this->w < e.w; }
};

int getParent(int P[], int k) {
  if (P[k] == k) {
    return k;
  } else {
    P[k] = getParent(P, P[k]);
    return P[k];
  }
}

void unionParent(int P[], int x, int y) {
  int p_x = getParent(P, x);
  int p_y = getParent(P, y);

  if (p_x >= p_y) {
    P[p_x] = p_y;
  } else {
    P[p_y] = p_x;
  }
}

bool findParent(int P[], int x, int y) {
  int p_x = getParent(P, x);
  int p_y = getParent(P, y);

  if (p_x == p_y) {
    return true;
  } else {
    return false;
  }
}

int solution(int n, vector<Edge> road) {
  int answer = 0;
  sort(road.begin(), road.end());

  int P[n];
  for (int i = 0; i < n; i++) {
    P[i] = i;
  }

  for (int i = 0; i < road.size(); i++) {
    // 부모 노드가 같지 않다면 Union
    if (!findParent(P, road[i].n[0] - 1, road[i].n[1] - 1)) {
      unionParent(P, road[i].n[0] - 1, road[i].n[1] - 1);
      answer += road[i].w;
    }
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
