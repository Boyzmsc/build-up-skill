#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getFirstN(int n)
{
    while (n >= 10)
    {
        n = n - (n / 10) * 10;
    }
    return n;
}

int getSecondN(int n)
{
    if (n < 10)
    {
        return 0;
    }
    else
    {
        while (n >= 10)
        {
            n = n / 10;
        }
        return n;
    }
}

void getCycleNum()
{
    int num;
    while (cin >> num)
    {
        int cycle = 0;
        while (true)
        {
            if ((num >= 0) && (num <= 99))
            {
                break;
            }
            else
            {
                continue;
            }
        }

        int original = num;
        int testNum = -1;
        int testFirstNum, testSecondNum;

        while (testNum != original)
        {
            cycle++;
            testFirstNum = getFirstN(num);
            testSecondNum = getSecondN(num);
            int firstNum = getFirstN(testFirstNum + testSecondNum);
            testNum = firstNum + testFirstNum * 10;
            num = testNum;
        }
        cout << cycle << endl;
    }
}

int main()
{
    getCycleNum();
}