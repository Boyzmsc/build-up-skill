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

    // index가 1부터 배열 끝까지 길이가 가장 긴
    // 증가하는 수열 dp1에 저장
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

    // index가 n-2부터 배열 앞까지 길이가 가장 긴
    // 증가하는 수열 dp2에 저장
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

    // dp1과 dp2의 수치를 합침으로써 길이가 가장 긴
    // 바이토닉 수열 dp에 저장
    for (int i = 0; i < n; i++)
    {
        dp[i] = dp1[i] + dp2[i] - 1;
    }

    // dp 인자 중 가장 큰 원소 반환
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}