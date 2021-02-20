#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int rlt = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push({i, num});
            pq.push(num);
        }

        while (!q.empty())
        {
            int file = q.front().first;
            int importance = q.front().second;
            q.pop();

            if (pq.top() == importance)
            {
                pq.pop();
                rlt++;
                if (file == m)
                {
                    cout << rlt << endl;
                    break;
                }
            }
            else
            {
                q.push({file, importance});
            }
        }
    }
}
