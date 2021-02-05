#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

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

        // cout << s1[i] << endl;
        // cout << "------" << endl;
        int n = dp.size();

        // cout << "size : " << n << endl;
        int index = 0;
        while (s2.find(s1[i], index) != string::npos && index < s2.length())
        {
            index = s2.find(s1[i], index);

            // cout << "index : " << index << endl;
            int check = second;

            for (int j = 0; j < n; j++)
            {
                if (dp[j].first < index)
                {
                    second = max(second, dp[j].second + 1);
                }
            }

            // if (second != check)
            // {
            first = index;
            dp.push_back({first, second});
            // cout << "push :" << first << " " << second << endl;
            // }
            // else
            // {
            //     cout << "Not push :" << first << " " << second << endl;
            // }
            index++;
        }
    }

    // cout << "========================" << endl;

    for (int i = 0; i < dp.size(); i++)
    {
        // cout << dp[i].first << " " << dp[i].second << endl;
        results.push_back(dp[i].second);
    }

    cout << *max_element(results.begin(), results.end()) << '\n';
}