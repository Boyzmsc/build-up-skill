#include <bits/stdc++.h>
using namespace std;

int DFA[3][1000];

int matchChar(char s) {
  if (s == 'A') {
    return 0;
  } else if (s == 'B') {
    return 1;
  } else if (s == 'C') {
    return 2;
  }
  return 0;
}

int matchDFA(string text, string pattern) {
  int answer = 0;
  int i, j;
  int t_len = text.length();
  int p_len = pattern.length();

  for (i = 0, j = 0; i < t_len && j <= p_len; i++) {
    j = DFA[matchChar(text[i])][j];

    if (j == p_len) {
      answer++;
    }
  }

  return answer;
}

void constructDFA(string pattern) {
  int p_len = pattern.length();

  DFA[matchChar(pattern[0])][0] = 1;

  int i, j;
  for (i = 0, j = 1; j < p_len; j++) {
    for (int k = 0; k < 3; k++) {
      DFA[k][j] = DFA[k][i];
    }

    DFA[matchChar(pattern[j])][j] = j + 1;
    i = DFA[matchChar(pattern[j])][i];
  }

  for (int k = 0; k < 3; k++) {
    DFA[k][j] = DFA[k][i];
  }
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    string pattern, text;
    cin >> pattern >> text;

    int p_len = pattern.length();
    int t_len = text.length();

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j <= p_len; j++) {
        DFA[i][j] = 0;
      }
    }

    constructDFA(pattern);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j <= p_len; j++) {
        if (DFA[i][j] > 0) {
          cnt++;
        }
      }
    }

    cout << cnt << " " << matchDFA(text, pattern) << endl;
  }
}
