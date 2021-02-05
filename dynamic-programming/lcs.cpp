#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// LCS(Longest Common Subsequence, 최장 공통 부분 수열)
// 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 코드
// C++의 string과 find() 함수를 이용, 동적계획법으로 구현

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() > s2.length())
    {
        string tmp;
        tmp = s1;
        s1 = s2;
        s2 = tmp;
    }

    // pair : index, count
    vector<pair<int, int>> dp{
        {0, 0},
    };
    vector<int> results;

    if (s2.find(s1[0]) != string::npos)
    {
        dp[0].first = s2.find(s1[0], 0);
        dp[0].second = 1;
    }
    else
    {
        dp[0].first = 0;
        dp[0].second = 0;
    }

    for (int i = 1; i < s1.length(); i++)
    {
        int first, second;
        if (s2.find(s1[i]) != string::npos)
        {
            first = s2.find(s1[i]);
            second = 1;
        }
        else
        {
            dp.push_back({0, 0});
            continue;
        }

        int n = dp.size();
        int index = 0;

        while (s2.find(s1[i], index) != string::npos && index < s2.length())
        {
            index = s2.find(s1[i], index);

            int check = second;

            for (int j = 0; j < n; j++)
            {
                if (dp[j].first < index)
                {
                    second = max(second, dp[j].second + 1);
                }
            }

            first = index;
            dp.push_back({first, second});
            index++;
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        results.push_back(dp[i].second);
    }

    cout << *max_element(results.begin(), results.end()) << '\n';
}