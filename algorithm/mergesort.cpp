#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void merge(vector<pair<int, string>> &v, int p, int mid, int r) {
  int n1 = mid - p + 1;
  int n2 = r - mid;

  vector<pair<int, string>> left;
  vector<pair<int, string>> right;

  int i = 0;
  int j = 0;

  for (i = 1; i <= n1; i++) {
    left.push_back(pair<int, string>(v[p + i - 1].first, v[p + i - 1].second));
  }
  for (j = 1; j <= n2; j++) {
    right.push_back(pair<int, string>(v[mid + j].first, v[mid + j].second));
  }

  left.push_back(pair<int, string>(99999, "dummy"));
  right.push_back(pair<int, string>(99999, "dummy"));
  i = 0;
  j = 0;

  for (int k = p; k <= r; k++) {
    if (left[i].first <= right[j].first) {
      v[k].first = left[i].first;
      v[k].second = left[i].second;
      i += 1;
    } else {
      v[k].first = right[j].first;
      v[k].second = right[j].second;
      j += 1;
    }
  }
}

void mergesort(vector<pair<int, string>> &v, int p, int r) {
  if (p < r) {
    int mid = (p + r) / 2;
    mergesort(v, p, mid);
    mergesort(v, mid + 1, r);
    merge(v, p, mid, r);
  }
}

////////////////////////////////////////////////////////////////////////////////

void mergeReverse(vector<pair<int, string>> &v, int p, int mid, int r) {
  int n1 = mid - p + 1;
  int n2 = r - mid;

  vector<pair<int, string>> left;
  vector<pair<int, string>> right;

  int i = 0;
  int j = 0;

  for (i = 1; i <= n1; i++) {
    left.push_back(pair<int, string>(v[p + i - 1].first, v[p + i - 1].second));
  }
  for (j = 1; j <= n2; j++) {
    right.push_back(pair<int, string>(v[mid + j].first, v[mid + j].second));
  }

  left.push_back(pair<int, string>(-1, "dummy"));
  right.push_back(pair<int, string>(-1, "dummy"));
  i = 0;
  j = 0;

  for (int k = p; k <= r; k++) {
    if (left[i].first >= right[j].first) {
      v[k].first = left[i].first;
      v[k].second = left[i].second;
      i += 1;
    } else {
      v[k].first = right[j].first;
      v[k].second = right[j].second;
      j += 1;
    }
  }
}

void mergesortReverse(vector<pair<int, string>> &v, int p, int r) {
  if (p < r) {
    int mid = (p + r) / 2;
    mergesortReverse(v, p, mid);
    mergesortReverse(v, mid + 1, r);
    mergeReverse(v, p, mid, r);
  }
}

int main(void) {
  int n;
  vector<pair<int, string>> v1;
  vector<pair<int, string>> v2;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int d;
    string s;
    cin >> d >> s;
    v1.push_back(pair<int, string>(d, s));
    v2.push_back(pair<int, string>(d, s));
  }

  // Merge Sort
  mergesort(v1, 0, v1.size() - 1);
  // Reverse Merge Sort
  mergesortReverse(v2, 0, v2.size() - 1);

  cout << "---------------------" << endl;

  for (int i = 0; i < n; i++) {
    cout << v1[i].first << ' ' << v1[i].second << endl;
  }

  cout << "---------------------" << endl;

  for (int i = 0; i < n; i++) {
    cout << v2[i].first << ' ' << v2[i].second << endl;
  }

  return 0;
}