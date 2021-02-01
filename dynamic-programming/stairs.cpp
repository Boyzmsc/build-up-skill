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

    int stairs[n + 1];
    int dp[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        stairs[i] = num;
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1], stairs[2]) + stairs[3];

    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
    }

    cout << dp[n] << '\n';
}