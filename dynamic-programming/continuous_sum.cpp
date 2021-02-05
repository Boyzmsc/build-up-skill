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

    // 연속된 수의 합 중에서 가장 큰 합을 구하기 위해,
    // 배열의 끝에서부터 첫번째까지 반대로 loop함
    // 또한 동적 계획법을 이용해, dp 배열에 해당 인자가
    // 가질 수 있는 가장 큰 합을 저장
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