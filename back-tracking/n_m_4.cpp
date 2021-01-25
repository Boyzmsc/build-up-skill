#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
int nums[8];

void getSequence(int count, int index)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << nums[i] + 1 << " ";
        }
        cout << '\n';
        return ;
    }

    for (int i = index; i < n; i++)
    {
        nums[count] = i;
        getSequence(count + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    getSequence(0, 0);
}