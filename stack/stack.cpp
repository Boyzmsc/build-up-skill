#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

// push X: 정수 X를 스택에 넣는 연산이다.
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 스택에 들어있는 정수의 개수를 출력한다.
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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