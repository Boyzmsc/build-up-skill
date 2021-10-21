#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll t;
  scanf("%lld", &t);
  for (ll i = 0; i < t; i++) {
    priority_queue<ll> maxHeap;
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    ll median = 0;
    ll n;
    scanf("%lld", &n);
    for (ll j = 1; j <= n; j++) {
      ll num;
      scanf("%lld", &num);

      if (j == 1) {
        minHeap.push(num);
        // cout << "median : " << minHeap.top() << endl;
        median += minHeap.top();
        continue;
      } else if (j == 2) {
        if (num <= minHeap.top()) {
          maxHeap.push(num);
        } else {
          maxHeap.push(minHeap.top());
          minHeap.pop();
          minHeap.push(num);
        }
        // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2 << endl;
        median += (maxHeap.top() + minHeap.top()) / 2;
        continue;
      }

      if (maxHeap.size() > minHeap.size()) {
        if (maxHeap.top() < num && num < minHeap.top()) {
          minHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2
            // <<endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << minHeap.top() << endl;
            median += minHeap.top();
          }
        } else if (num <= maxHeap.top()) {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
          maxHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2
            // <<endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << maxHeap.top() << endl;
            median += maxHeap.top();
          }
        } else if (minHeap.top() <= num) {
          minHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2
            // <<endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << maxHeap.top() << endl;
            median += maxHeap.top();
          }
        }
      } else {
        if (maxHeap.top() < num && num < minHeap.top()) {
          minHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2 <<
            // endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << minHeap.top() << endl;
            median += minHeap.top();
          }
        } else if (num <= maxHeap.top()) {
          maxHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2 <<
            // endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << maxHeap.top() << endl;
            median += maxHeap.top();
          }
        } else if (minHeap.top() <= num) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
          minHeap.push(num);

          if (j % 2 == 0) {
            // Even Case
            // cout << "median : " << (maxHeap.top() + minHeap.top()) / 2 <<
            // endl;
            median += (maxHeap.top() + minHeap.top()) / 2;
          } else {
            // Odd Case
            // cout << "median : " << maxHeap.top() << endl;
            median += maxHeap.top();
          }
        }
      }
    }

    printf("%lld\n", median % 10);
  }
}