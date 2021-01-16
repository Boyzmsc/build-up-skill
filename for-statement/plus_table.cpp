#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getTestCaseNum()
{
    int t;
    cin >> t;
    return t;
}

void getPlusTable(int testNum)
{
    for (int i = 0; i < testNum; i++)
    {
        int a, b;
        cin >> a >> b;
        while (true)
        {
            if ((a > 0) && (b < 10))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        cout << a + b << endl;
    }
}

int main()
{
    int testCase = getTestCaseNum();
    getPlusTable(testCase);
}
