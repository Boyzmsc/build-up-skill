#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   scanf("%d", &t);
   for (int w = 0; w < t; w++)
   {
      int n;
      scanf("%d", &n);

      int dp[n + 1][n + 1]{0,};

      for (int i = 1; i <= n; i++)
      {
         int value;
         scanf("%d", &value);
         dp[0][i] = value;
      }

      // Dp

      // Print Vector
      for (int i = 0; i < n + 1; i++)
      {
         for (int j = 0; j < n + 1; j++)
         {
            cout << dp[i][j] << " ";
         }
         cout << endl;
      }
   }
}