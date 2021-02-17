#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    int seq[100001];
    vector<char> results;

    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }

    int num = 1;
    int i = 1;
    while (num <= n)
    {
        if (s.size() != 0 && s.top() == seq[i])
        {
            i++;
            s.pop();
            results.push_back('-');
        }
        else
        {
            s.push(num);
            num++;
            results.push_back('+');
        }
    }

    while (s.size() != 0)
    {
        if (seq[i] == s.top())
        {
            i++;
            s.pop();
            results.push_back('-');
        }
        else
        {
            break;
        }
    }

    if (s.size() == 0)
    {
        for (int i = 0; i < results.size(); i++)
        {
            cout << results[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
}