#include <bits/stdc++.h>
using namespace std;

// stack에 들어가면 방문한거로 판단
// 해당 위치를 true로 해준다.
void dfs(int start, vector<vector<int>> graph, bool check[]) {
  stack<int> s;
  s.push(start);
  check[start] = true;
  printf("%d ", start);

  // distance : pred
  vector<pair<int, int>> vertex(graph.size());
  vertex[start].first = 0;
  vertex[start].second = start;

  // start : finish
  vector<pair<int, int>> time_vertex(graph.size());
  int time = 0;

  while (!s.empty()) {
    time++;

    int current_node = s.top();
    s.pop();

    if (time_vertex[current_node].first > 0) {
      printf("%d ", current_node);

      // set finish time
      time_vertex[current_node].second = time;
      continue;
    }

    // set start time
    time_vertex[current_node].first = time;

    int distance = vertex[current_node].first;
    int pred = current_node;

    bool flag = false;
    for (int i = 0; i < graph[current_node].size(); i++) {
      int next_node = graph[current_node][i];

      // 방문하지 않았다면
      if (check[next_node] == false) {
        flag = true;
        printf("%d ", next_node);
        check[next_node] = true;

        vertex[next_node].first = distance + 1;
        vertex[next_node].second = pred;

        // pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
        s.push(current_node);
        s.push(next_node);
        break;
      }
    }

    if (!flag) {
      printf("%d ", current_node);

      // set finish time
      time_vertex[current_node].second = ++time;
    }
  }

  // Check
  cout << endl;
  for (int i = 1; i < vertex.size(); i++) {
    cout << "[ " << i << " ]" << endl;
    cout << vertex[i].first << " " << vertex[i].second << endl;
    cout << time_vertex[i].first << " " << time_vertex[i].second << endl;
  }
}

int main() {

  int n, m, start;
  cin >> n >> m >> start;

  vector<vector<int>> graph(n + 1);
  bool check[n + 1] = {
      false,
  };

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
  }

  // Sorting은 왜 한거지?
  // 나중에 하나의 정점에서 다음을 탐색할 때
  // node 값에 순차적으로 접근해야하기 때문
  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  // DFS
  dfs(start, graph, check);
  printf("\n");

  return 0;
}