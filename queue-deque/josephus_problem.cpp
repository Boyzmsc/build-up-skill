#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    deque<int> nums;

    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }

    cout << "<";
    while (!nums.empty())
    {
        for (int j = 0; j < k - 1; j++)
        {
            int tmp = nums.front();
            nums.push_back(tmp);
            nums.pop_front();
        }
        
        if (nums.size() == 1)
        {
            cout << nums.front() << ">";
        }
        else
        {
            cout << nums.front() << ", ";
        }

        nums.pop_front();
    }
}
