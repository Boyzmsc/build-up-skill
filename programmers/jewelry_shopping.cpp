#include <bits/stdc++.h>
using namespace std;

void solution(vector<string> gems) {
  int start = 0;
  int end = 0;

  // 진열대에서 보석의 종류 얻어오기
  // 중복 없게 하는 set 사용
  set<string> gem_kinds(gems.begin(), gems.end());
  int kinds = gem_kinds.size();

  map<string, int> gem;

  int shortest = INT_MAX;

  int rlt_start = 1;
  int rlt_end = gems.size();

  // 조건에 맞는 구간 찾을 때까지 끝점 증가
  while (end < gems.size()) {
    auto it = gem.find(gems[end]);

    if (it == gem.end()) {
      gem[gems[end]] = 1;
    } else {
      gem[gems[end]] += 1;
    }
    end++;

    // 모든 종류를 포함했을 때
    if (gem.size() == kinds) {
      // 구간 최소화를 위해 시작점 증가
      while (start < end) {
        if (gem[gems[start]] <= 1) {
          break;
        }
        gem[gems[start]] -= 1;
        start += 1;
      }

      // 가장 짧은 구간과 그 길이 갱신
      if (end - start < shortest) {
        rlt_start = start + 1;
        rlt_end = end;
        shortest = end - start;
      }
    }
  }

  cout << rlt_start << " " << rlt_end << endl;
}

int main() {
  int n;
  cin >> n;
  vector<string> gems;

  while (n--) {
    string gem;
    cin >> gem;
    gems.push_back(gem);
  }

  solution(gems);
}