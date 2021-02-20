#include <bits/stdc++.h>

using namespace std;

// push_front X: 정수 X를 덱의 앞에 넣는다.
// push_back X: 정수 X를 덱의 뒤에 넣는다.
// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 덱에 들어있는 정수의 개수를 출력한다.
// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
// front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
deque<int> nums;

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

        if (cmd == "push_front")
        {
            int n;
            cin >> n;
            nums.push_front(n);
        }else if (cmd == "push_back")
        {
            int n;
            cin >> n;
            nums.push_back(n);
        }
        else if (cmd == "pop_front")
        {
            if (nums.size() == 0)
            {
                cout << "-1\n";
            }
            else
            {
                cout << nums.front() << '\n';
                nums.pop_front();
            }
        }else if (cmd == "pop_back")
        {
            if (nums.size() == 0)
            {
                cout << "-1\n";
            }
            else
            {
                cout << nums.back() << '\n';
                nums.pop_back();
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
