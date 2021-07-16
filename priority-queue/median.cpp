#include <bits/stdc++.h>
using namespace std;

struct max_compare
{
   bool operator()(int n1, int n2)
   {
      return n1 < n2;
   }
};

struct min_compare
{
   bool operator()(int n1, int n2)
   {
      return n1 > n2;
   }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   scanf("%d", &t);

   priority_queue<int, vector<int>, max_compare> max_pq;
   priority_queue<int, vector<int>, min_compare> min_pq;

   for (int i = 0; i < t; i++)
   {
      int value;
      scanf("%d", &value);

      if (max_pq.size() == min_pq.size())
      {
         max_pq.push(value);
      }
      else if (max_pq.size() > min_pq.size())
      {
         min_pq.push(value);
      }

      if (min_pq.empty())
      {
         printf("%d\n", max_pq.top());
         continue;
      }

      if (max_pq.top() > min_pq.top())
      {
         // Switch
         int maxV = max_pq.top();
         int minV = min_pq.top();

         max_pq.pop();
         min_pq.pop();

         min_pq.push(maxV);
         max_pq.push(minV);
      }

      printf("%d\n", max_pq.top());
   }
}