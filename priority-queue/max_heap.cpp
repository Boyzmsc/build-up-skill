#include <bits/stdc++.h>
using namespace std;

struct compare
{
   bool operator()(int n1, int n2)
   {
      return n1 < n2;
   }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   scanf("%d", &t);

   priority_queue<int, vector<int>, compare> pq;

   for (int i = 0; i < t; i++)
   {
      int value;
      scanf("%d", &value);
      if (value == 0)
      {
         if (pq.empty())
         {
            printf("%d\n", 0);
         }
         else
         {
            printf("%d\n", pq.top());
            pq.pop();
         }
      }
      else
      {
         pq.push(value);
      }
   }
}