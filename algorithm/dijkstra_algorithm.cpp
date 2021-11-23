#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int solution(int N, vector<vector<int>> road, int K) {
  vector<pair<int, bool>> city(N + 1, pair<int, bool>(INF, false));
  vector<pair<int, int>> dist(N + 1, pair<int, int>(INF, 0));

  // Init city
  city[1].first = 0;

  // Init dist
  dist[1].first = 0;
  dist[1].second = 1;

  int cnt = 1;
  while (cnt < N) {
    // Get Min City
    int chk = INF;
    int u;

    for (int i = 1; i < city.size(); i++) {
      if (city[i].first < chk && city[i].second == false) {
        chk = city[i].first;
        u = i;
      }
    }

    city[u].second = true;
    cnt++;

    for (int i = 0; i < road.size(); i++) {
      if (road[i][0] == u) {
        int v = road[i][1];
        if (city[v].second == false &&
            dist[v].first > dist[u].first + road[i][2]) {
          dist[v].first = dist[u].first + road[i][2];
          dist[v].second = u;

          city[v].first = dist[u].first + road[i][2];
        }
      } else if (road[i][1] == u) {
        int v = road[i][0];
        if (city[v].second == false &&
            dist[v].first > dist[u].first + road[i][2]) {
          dist[v].first = dist[u].first + road[i][2];
          dist[v].second = u;

          city[v].first = dist[u].first + road[i][2];
        }
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    if (dist[i].first <= K) {
      answer++;
    }
  }

  return answer;
}