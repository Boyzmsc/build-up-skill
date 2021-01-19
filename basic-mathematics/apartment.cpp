#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int getTestCaseNum()
{
    int t;
    cin >> t;
    return t;
}

void getRoomNum(int testNum)
{
    int apartment[15][15];
    for (int j = 0; j < 15; j++)
    {
        for (int k = 0; k < 15; k++)
        {
            apartment[j][k] = 0;
        }
    }
    for (int i = 1; i < 15; i++)
    {
        apartment[0][i] = i;
    }
    // k층,n-1호 사는 사람 + k-1층,n호 사는 사람
    for (int j = 1; j < 15; j++)
    {
        for (int k = 1; k < 15; k++)
        {
            apartment[j][k] = apartment[j - 1][k] + apartment[j][k - 1];
        }
    }
    // for (int j = 1; j < 15; j++)
    // {
    //     for (int k = 1; k < 15; k++)
    //     {
    //         cout << j << " " << k << " : " << apartment[j][k] << endl;
    //     }
    // }
    for (int i = 0; i < testNum; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << (int)apartment[x][y] << endl;
    }
}

int main()
{
    int testCase = getTestCaseNum();
    getRoomNum(testCase);
}