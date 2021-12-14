#include <bits/stdc++.h>
using namespace std;

int INF = 9999;
int NIL = 9999;

void printPath(vector<vector<int>> pred, int i, int j) {
  if (i == j) {
    cout << i << " ";
  } else if (pred[i - 1][j - 1] == NIL) {
    cout << "No path from " << i << " to " << j << " exists" << endl;
  } else {
    printPath(pred, i, pred[i - 1][j - 1]);
    cout << j << " ";
  }
}

void solution(int N, vector<vector<int>> input) {

  vector<vector<int>> weight(N, vector<int>(N, INF));

  int tmp = 0;
  while (tmp < N) {
    weight[tmp][tmp] = 0;
    tmp++;
  }
  for (int i = 0; i < input.size(); i++) {
    int start = input[i][0];
    int end = input[i][1];
    int w = input[i][2];

    weight[start - 1][end - 1] = w;
  }

  vector<vector<int>> pred(N, vector<int>(N, NIL));

  tmp = 0;
  while (tmp < N) {
    pred[tmp][tmp] = NIL;
    tmp++;
  }
  for (int i = 0; i < input.size(); i++) {
    int start = input[i][0];
    int end = input[i][1];
    int w = input[i][2];

    pred[start - 1][end - 1] = start;
  }

  vector<vector<vector<int>>> D;
  // D(0)
  D.push_back(weight);

  vector<vector<vector<int>>> P;
  // P(0)
  P.push_back(pred);

  for (int k = 0; k < N; k++) {

    // new N*N matrix
    vector<vector<int>> d(N, vector<int>(N, INF));
    int tmp = 0;
    while (tmp < N) {
      d[tmp][tmp] = 0;
      tmp++;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = min(D[k][i][j], D[k][i][k] + D[k][k][j]);
      }
    }

    D.push_back(d);

    // new N*N matrix
    vector<vector<int>> p(N, vector<int>(N, NIL));
    tmp = 0;
    while (tmp < N) {
      p[tmp][tmp] = NIL;
      tmp++;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (D[k][i][j] <= D[k][i][k] + D[k][k][j]) {
          p[i][j] = P[k][i][j];
        } else {
          p[i][j] = P[k][k][j];
        }
      }
    }

    P.push_back(p);
  }

  // Print Result
  cout << "[ Weight ]" << endl;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << D[N][i][j] << " ";
    }
    cout << endl;
  }

  cout << "\n[ Pred ]" << endl;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << P[N][i][j] << " ";
    }
    cout << endl;
  }

  cout << "\n[ Result ]" << endl;
  // 5번 -> 2번
  printPath(P[N], 5, 2);
}

int main() {
  int N = 5;
  vector<vector<int>> input = {{1, 2, 3}, {1, 5, -4}, {1, 3, 8},
                               {2, 4, 1}, {2, 5, 7},  {3, 2, 4},
                               {4, 1, 2}, {4, 3, -5}, {5, 4, 6}};

  solution(N, input);
}