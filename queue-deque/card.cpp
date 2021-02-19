#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<int> cards;

    for (int i = 1; i <= n; i++)
    {
        cards.push_back(i);
    }

    while (true)
    {
        if (cards.size() == 1)
        {
            break;
        }
        cards.pop_front();
        if (cards.size() == 1)
        {
            break;
        }
        int top = cards.front();
        cards.push_back(top);
        cards.pop_front();
    }

    cout << cards.front() << '\n';
}
