#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll hist[100000];
stack<pair<ll, int>> s;
int t;

// 히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램
int main()
{
    while (true)
    {
        cin >> t;
        if (t == 0)
        {
            break;
        }

        ll maxArea = 0;

        for (int i = 0; i < t; i++)
        {
            ll n;
            cin >> n;
            hist[i] = n;
        }

        for (int i = 0; i < t; i++)
        {
            int idx = i;
            while (!s.empty() && s.top().first >= hist[i])
            {
                maxArea = max(maxArea, (i - s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({hist[i], idx});
        }

        while (!s.empty())
        {
            maxArea = max(maxArea, (t - s.top().second) * s.top().first);
            s.pop();
        }

        cout << maxArea << '\n';
    }
}