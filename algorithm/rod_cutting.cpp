#include <bits/stdc++.h>
using namespace std;

struct RC {
  vector<int> eValue;
  vector<int> eCase;
};

RC rodCutting(vector<int> p, int len) {
  RC rc;

  for (int i = 0; i <= len; i++) {
    rc.eValue.push_back(0);
    rc.eCase.push_back(0);
  }

  for (int i = 1; i <= len; i++) {
    int maxValue = -1;
    for (int j = 1; j <= i; j++) {
      if (maxValue < p[j] + rc.eValue[i - j]) {
        maxValue = p[j] + rc.eValue[i - j];
        rc.eCase[i] = j;
      }
    }
    rc.eValue[i] = maxValue;
  }

  return rc;
}

void printRodCut(vector<int> p, int len) {
  RC rlt = rodCutting(p, len);
  while (len > 0) {
    printf("%d ", rlt.eCase[len]);
    len -= rlt.eCase[len];
  }
}

int main() {
  vector<int> p;
  int num, len;
  scanf("%d", &num);

  for (int i = 0; i <= num; i++) {
    if (i == 0) {
      p.push_back(0);
    } else {
      int price;
      scanf("%d", &price);
      p.push_back(price);
    }
  }

  cout << "------------------" << endl;
  scanf("%d", &len);

  /////////////////////////////////////////////
  RC rlt = rodCutting(p, len);
  /////////////////////////////////////////////

  /////////////////////////////////////////////
  // Print Vector
  cout << "------------------" << endl;
  for (int i = 1; i <= len; i++) {
    printf("%d ", rlt.eValue[i]);
  }
  cout << endl;

  for (int i = 1; i <= len; i++) {
    printf("%d ", rlt.eCase[i]);
  }
  cout << endl;
  /////////////////////////////////////////////

  /////////////////////////////////////////////
  // Answer
  cout << "------------------" << endl;
  // Answer (Value)
  printf("%d\n", rlt.eValue[len]);
  // Answer (Case)
  printRodCut(p, len);
  /////////////////////////////////////////////
}