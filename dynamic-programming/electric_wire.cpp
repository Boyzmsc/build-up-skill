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
    vector<pair<int, int>> pos;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        pos.push_back({start, end});
    }

    sort(pos.begin(), pos.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << pos[i].first << " " << pos[i].second << endl;
    // }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pos[j].first < pos[i].first && pos[j].second < pos[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] << endl;
    // }

    cout << n - *max_element(dp.begin(), dp.end()) << "\n";
}