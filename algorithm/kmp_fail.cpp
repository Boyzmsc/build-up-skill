#include <bits/stdc++.h>
using namespace std;

vector<int> getFail(string pattern) {
  int m = pattern.length();
  int j = 0;
  vector<int> fail(m, 0);

  for (int i = 1; i < m; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = fail[j - 1];
    }

    if (pattern[i] == pattern[j]) {
      fail[i] = ++j;
    } else {
      fail[i] = j;
    }
  }

  return fail;
}

vector<int> kmp(string text, string pattern) {
  vector<int> answer;
  vector<int> fail = getFail(pattern);

  int n = text.length();
  int m = pattern.length();
  int j = 0;

  for (int i = 0; i < n; i++) {
    while (j > 0 && text[i] != pattern[j]) {
      j = fail[j - 1];
    }

    if (text[i] == pattern[j]) {
      if (j == m - 1) {
        answer.push_back(i - j);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return answer;
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    string pattern, text;
    cin >> pattern >> text;
    vector<int> fail = getFail(pattern);
    vector<int> rlt = kmp(text, pattern);

    for (int i = 0; i < fail.size(); i++) {
      cout << fail[i] << " ";
    }
    cout << endl;

    cout << rlt.size() << endl;
  }
}
