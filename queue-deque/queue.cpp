#include <bits/stdc++.h>

using namespace std;

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
queue<int> nums;

int main()
{
    // 입력, 출력의 버퍼를 최소화하기 위한 함수
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    string cmd;
    
    while (t--)
    {
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
                cout << "-1\n";
            }
            else
            {
                cout << nums.front() << '\n';
                nums.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << nums.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (nums.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (cmd == "front")
        {
            if (nums.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << nums.front() << '\n';
            }
        }
        else
        {
            if (nums.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << nums.back() << '\n';
            }
        }
    }
}
