#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
bool isVisit[8];
int nums[8];

void getSequence(int count, int index)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << nums[i] + 1 << " ";
        }
        cout << endl;
    }

    for (int i = index; i < n; i++)
    {
        if (!isVisit[i])
        {
            isVisit[i] = true;
            nums[count] = i;
            getSequence(count + 1, i);
            isVisit[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    getSequence(0, 0);
}