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
    stack<int> nums;
    while (t--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int n;
            cin >> n;
            nums.push(n);
        }
        else if (cmd == "pop")
        {
            if (nums.size() == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << nums.top() << endl;
                nums.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << nums.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (nums.size() == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == "top")
        {
            if (nums.size() == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << nums.top() << endl;
            }
        }
    }
}