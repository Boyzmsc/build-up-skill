#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
vector<pair<int, ll>> v;

bool compare1(pair<int, ll> &a, pair<int, ll> &b)
{
   return a.second < b.second;
}

bool compare2(pair<int, ll> &a, pair<int, ll> &b)
{
   return a.first < b.first;
}

int main()
{
   int t;
   cin >> t;

   for (int i = 0; i < t; i++)
   {
      ll value;
      cin >> value;
      v.push_back(make_pair(i, value));
   }

   sort(v.begin(), v.end(), compare1);

   int compV = 0;
   int tmp;
   for (int i = 0; i < v.size(); i++)
   {
      if (i == 0)
      {
         tmp = v[i].second;
         v[i].second = compV;
      }
      else if (v[i].second == tmp)
      {
         v[i].second = compV;
      }
      else if (v[i].second != tmp)
      {
         compV++;
         tmp = v[i].second;
         v[i].second = compV;
      }
   }

   sort(v.begin(), v.end(), compare2);

   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i].second << " ";
   }
}