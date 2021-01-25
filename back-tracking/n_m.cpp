#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
bool isVisit[8];
int nums[8];

void getSequence(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", nums[i] + 1);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        if (!isVisit[i])
        {
            isVisit[i] = true;
            nums[count] = i;
            getSequence(count + 1);
            isVisit[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    getSequence(0);
}