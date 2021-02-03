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

    int arr[n];
    vector<int> dp(n);
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = dp1[i] + dp2[i] - 1;
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}