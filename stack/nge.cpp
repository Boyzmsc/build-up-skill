#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int nums[1000001];
int rlt[1000001];

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    stack<int> idx;

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (st.size() != 0 && st.top() < nums[i])
        {
            rlt[idx.top()] = nums[i];
            st.pop();
            idx.pop();
        }
        st.push(nums[i]);
        idx.push(i);
    }

    while (idx.size() > 0)
    {
        rlt[idx.top()] = -1;
        idx.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << rlt[i] << ' ';
    }
}