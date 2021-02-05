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
    int dp[n];
    vector<int> results;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    dp[0] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[n - i - 1] = max(arr[i] + dp[n - i - 2], arr[i]);
    }

    for(int i = 0;i< n;i++){
        results.push_back(dp[i]);
    }

    // dp의 원소들 중 가장 큰 원소 반환
    cout << *max_element(results.begin(), results.end()) << "\n";
}