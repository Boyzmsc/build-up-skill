#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int rlt = 0;
    deque<int> dq;
    deque<int>::iterator it;
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }

    while (!q.empty())
    {
        int check = q.front();

        if (dq.front() == check)
        {
            dq.pop_front();
            q.pop();
        }
        else
        {
            int count = 1;

            for (it = dq.begin(); it != dq.end(); it++)
            {
                if (*it == check)
                {
                    break;
                }
                count++;
            }

            if (count > dq.size() / 2 + 1)
            {
                int tmp_b = dq.back();
                dq.pop_back();
                dq.push_front(tmp_b);
                rlt++;
            }
            else
            {
                int tmp_f = dq.front();
                dq.pop_front();
                dq.push_back(tmp_f);
                rlt++;
            }
        }

        // print deque
        for (it = dq.begin(); it != dq.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << rlt << endl;
}
