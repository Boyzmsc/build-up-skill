#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int dp[num + 1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 3;
    for (int i = 6; i <= num; i++)
    {
        int count = 0;
        int n = i;
        while (true)
        {
            if (n == 1)
            {
                break;
            }
            count++;
            if (n % 3 == 0 && dp[n / 3] < dp[n - 1])
            {
                n /= 3;
            }
            else if (n % 2 == 0 && dp[n / 2] < dp[n - 1])
            {
                n /= 2;
            }
            else
            {
                n -= 1;
            }
        }
        dp[i] = count;
    }
    cout << dp[num] << '\n';
}