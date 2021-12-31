#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack Problem

bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first / a.second) > (b.first / b.second);
}

int FK(vector<pair<int, int>> items, int capacity) {
  sort(items.begin(), items.end(), cmp);

  int totalValue = 0;
  int load = 0;
  int i = 0;

  while (load < capacity && i < items.size()) {
    if (items[i].second <= capacity - load) {
      totalValue += items[i].first;
      load += items[i].second;
    } else {
      totalValue += ((capacity - load) * items[i].first / items[i].second);
      load += capacity - load;
    }
    i++;
  }

  return totalValue;
}

int main() {
  vector<pair<int, int>> items;
  items.push_back({60, 10});
  items.push_back({100, 20});
  items.push_back({120, 30});

  cout << FK(items, 50) << endl;
}