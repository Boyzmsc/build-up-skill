#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt_swap_hoare;
ll cnt_swap_lomuto;
ll cnt_compare_hoare;
ll cnt_compare_lomuto;

int partitionHoare(vector<ll> &v, int low, int high) {
  int pivot = v[low];
  int i = low - 1;
  int j = high + 1;
  while (true) {
    do {
      i += 1;
      cnt_compare_hoare++;
    } while (v[i] < pivot);

    do {
      j -= 1;
      cnt_compare_hoare++;
    } while (v[j] > pivot);

    if (i < j) {
      // swap
      cnt_swap_hoare++;
      ll tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    } else {
      return j;
    }
  }
}

void quicksortHoare(vector<ll> &v, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = partitionHoare(v, low, high);
  quicksortHoare(v, low, pivot);
  quicksortHoare(v, pivot + 1, high);
}

int partitionLomuto(vector<ll> &v, int low, int high) {
  int pivot = v[low];
  int j = low;
  for (int i = low + 1; i <= high; i++) {
    cnt_compare_lomuto++;
    if (v[i] < pivot) {
      j += 1;
      // swap
      cnt_swap_lomuto++;
      ll tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }
  }

  int idx_pivot = j;
  // swap
  cnt_swap_lomuto++;
  ll tmp = v[idx_pivot];
  v[idx_pivot] = v[low];
  v[low] = tmp;
  return idx_pivot;
}

void quicksortLomuto(vector<ll> &v, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = partitionLomuto(v, low, high);
  quicksortLomuto(v, low, pivot - 1);
  quicksortLomuto(v, pivot + 1, high);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    vector<ll> v1;
    vector<ll> v2;
    for (int j = 0; j < n; j++) {
      ll data;
      scanf("%lld", &data);
      v1.push_back(data);
      v2.push_back(data);
    }
    cnt_swap_hoare = 0;
    cnt_swap_lomuto = 0;
    cnt_compare_hoare = 0;
    cnt_compare_lomuto = 0;

    quicksortHoare(v1, 0, v1.size() - 1);
    quicksortLomuto(v2, 0, v2.size() - 1);

    printf("%lld %lld %lld %lld\n", cnt_swap_hoare, cnt_swap_lomuto,
           cnt_compare_hoare, cnt_compare_lomuto);
  }
}