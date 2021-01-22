#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int getTitle(int n)
{
    int res;
    int count = 0;
    int num = 666;
    while (count != n)
    {
        int tmp = num;
        bool corr = false;
        while (tmp >= 666)
        {
            if (tmp % 1000 == 666)
            {
                corr = true;
            }
            tmp /= 10;
        }
        if (corr)
        {
            count++;
        }
        num++;
    }
    return num - 1;
}

int main()
{
    int n;
    cin >> n;
    cout << getTitle(n) << '\n';
}