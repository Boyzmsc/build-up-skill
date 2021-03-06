#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int wines[n + 1]{
        0,
    };
    int dp[n + 1]{
        0,
    };

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        wines[i] = num;
    }

    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];
    dp[3] = max(wines[1] + wines[2], max(wines[1] + wines[3], wines[2] + wines[3]));

    if (n >= 4)
    {
        for (int i = 4; i <= n; i++)
        {
            // dp(i-2) | x o 인 경우,
            // dp(i-3) | x o o 인 경우,
            // dp(i-1) | x  인 경우 중 최댓값 dp[i]에 저장
            dp[i] = max(dp[i - 2] + wines[i], max(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 1]));
        }
    }

    cout << dp[n] << endl;
}