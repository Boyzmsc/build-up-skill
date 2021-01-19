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
    for (int i = 0; i < testNum; i++)
    {
        int w, h, n;
        cin >> h >> w >> n;
        while (true)
        {
            if ((h >= 1 && w <= 99) && (n >= 1 && n <= h * w))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        int column = n / h + 1;
        int row = n % h;
        if (row == 0)
        {
            row = h;
            column = n / h;
        }
        if (row < 10 && column < 10)
        {
            cout << row << "0" << column << endl;
        }
        else if (row < 10 && column >= 10)
        {
            cout << row << column << endl;
        }
        else if (row >= 10 && column < 10)
        {
            cout << row << "0" << column << endl;
        }
        else
            cout << row << column << endl;
    }
}

int main()
{
    int testCase = getTestCaseNum();
    getRoomNum(testCase);
}