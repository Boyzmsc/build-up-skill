#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int getTestCaseNum()
{
    int t;
    cin >> t;
    return t;
}

void getWarpCount(int testNum)
{
    for (int k = 0; k < testNum; k++)
    {
        long x, y, distance;
        cin >> x >> y;
        distance = y - x;
        long i = 1;
        while (i++)
        {
            if (i * i > distance)
            {
                break;
            }
        }
        if (pow(i - 1, 2) == y - x)
        {
            cout << 2 * i - 3 << endl;
        }
        else if ((pow(i, 2) + pow(i - 1, 2)) / 2 >= y - x)
        {
            cout << 2 * (i - 2) << endl;
        }
        else
        {
            cout << 2 * i - 1 << endl;
        }
    }
}

int main()
{
    int testCase = getTestCaseNum();
    getWarpCount(testCase);
}