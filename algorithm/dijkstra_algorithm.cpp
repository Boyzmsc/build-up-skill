#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int solution(int N, vector<vector<int>> road, int K) {
  // City : Key
  vector<pair<int, int>> city;

  // Key : Pre-Vertex
  vector<pair<int, int>> dist;

  // Init city
  city.push_back(make_pair(1, 0));
  for (int i = 2; i <= N; i++) {
    city.push_back(make_pair(i, INT_MAX));
  }

  // Init dist
  dist.push_back(make_pair(0, 1)); // Dummy
  dist.push_back(make_pair(0, 1));
  for (int i = 2; i <= N; i++) {
    dist.push_back(make_pair(INT_MAX, -1));
  }

  // Operation
  while (city.size() != 0) {
    // Get Min City
    sort(city.begin(), city.end(), cmp);
    int u = city[0].first;
    city.erase(city.begin());

    for (int i = 0; i < road.size(); i++) {
      if (road[i][0] == u) {
        int v = road[i][1];
        if (dist[v].first > dist[u].first + road[i][2]) {
          dist[v].first = dist[u].first + road[i][2];
          dist[v].second = u;

          for (int j = 0; j < city.size(); j++) {
            if (city[j].first == v) {
              city[j].second = dist[u].first + road[i][2];
            }
          }
        }
      } else if (road[i][1] == u) {
        int v = road[i][0];
        if (dist[v].first > dist[u].first + road[i][2]) {
          dist[v].first = dist[u].first + road[i][2];
          dist[v].second = u;

          for (int j = 0; j < city.size(); j++) {
            if (city[j].first == v) {
              city[j].second = dist[u].first + road[i][2];
            }
          }
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