#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getTestCaseNum()
{
    int t;
    while (true)
    {
        cin >> t;
        if ((t > 0) && (t <= 1000000))
        {
            break;
        }
        else
        {
            continue;
        }
    }
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
            if ((a >= 1) && (a <= 1000) && (b >= 1) && (b <= 1000))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        cout << a + b << "\n";
    }
}

int main()
{
    // C++의 표준 stream의 동기화를 끊는 역할
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int testCase = getTestCaseNum();
    getPlusTable(testCase);
}
