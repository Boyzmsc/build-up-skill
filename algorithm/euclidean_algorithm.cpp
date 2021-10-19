#include <bits/stdc++.h>
using namespace std;

int euclid(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return euclid(b, a % b);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", euclid(a, b));
  }
}