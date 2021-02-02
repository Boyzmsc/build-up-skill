#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> dp;
    long long result = 0;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);

    while (n > 1)
    {
        long long tmp[10]{
            0,
        };
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == 0)
            {
                continue;
            }
            else
            {
                if (i == 0)
                {
                    tmp[1] += dp[i] % 1000000000;
                }
                else if (i == 9)
                {
                    tmp[8] += dp[i] % 1000000000;
                }
                else
                {
                    tmp[i - 1] += dp[i] % 1000000000;
                    tmp[i + 1] += dp[i] % 1000000000;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i] = tmp[i];
            // cout << i << " " << dp[i] << endl;
        }
        n--;
    }

    for (int i = 0; i < dp.size(); i++)
    {
        result += (dp[i] % 1000000000);
    }
    cout << result % 1000000000 << endl;
}