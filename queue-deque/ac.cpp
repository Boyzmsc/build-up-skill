#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string cmd;
        cin >> cmd;

        int len;
        cin >> len;

        string arr;
        cin >> arr;

        deque<int> dq;
        deque<int>::iterator it;

        int idx = 1;
        while (idx < arr.length())
        {
            string tmp = "\n";
            while (true)
            {
                if (arr[idx] == ',' || arr[idx] == ']')
                {
                    break;
                }
                else
                {
                    tmp += arr[idx];
                    idx++;
                }
            }
            if (tmp == "\n")
            {
                break;
            }
            else
            {
                dq.push_back(stoi(tmp));
                idx++;
            }
        }

        bool isError = false;
        bool reverse = false;

        for (int i = 0; i < cmd.length(); i++)
        {
            if (cmd[i] == 'R')
            {
                reverse = !reverse;
            }
            else if (cmd[i] == 'D')
            {
                if (dq.size() == 0)
                {
                    isError = true;
                    break;
                }
                else
                {
                    if (reverse)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }
        }

        if (isError)
        {
            cout << "error" << '\n';
        }
        else
        {
            cout << '[';
            if (reverse)
            {
                for (it = dq.end() - 1; it != dq.begin() - 1; it--)
                {
                    if (it == dq.begin())
                    {
                        cout << *it;
                    }
                    else
                    {

                        cout << *it << ",";
                    }
                }
                cout << "]" << '\n';
            }
            else
            {
                for (it = dq.begin(); it != dq.end(); it++)
                {
                    if (it == dq.end() - 1)
                    {
                        cout << *it;
                    }
                    else
                    {

                        cout << *it << ",";
                    }
                }
                cout << "]" << '\n';
            }
        }

        // for (it = dq.begin(); it != dq.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
}
