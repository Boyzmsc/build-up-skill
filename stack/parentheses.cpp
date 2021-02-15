#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string line;
        cin >> line;

        stack<char> s;
        bool check = true;

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '(')
            {
                s.push(line[i]);
            }
            else if (line[i] == ')' && s.size() == 0)
            {
                cout << "NO" << '\n';
                check = false;
                break;
            }
            else if (line[i] == ')' && s.size() != 0)
            {
                s.pop();
            }
        }

        if (!check)
        {
            continue;
        }

        if (s.size() == 0)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}