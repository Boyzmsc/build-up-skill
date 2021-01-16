#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getNum()
{
    int t;
    while (true)
    {
        cin >> t;
        if ((t > 0) && (t <= 100000))
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

void getNTable(int num)
{
    for (int i = 1; i <= num; i++)
    {
        cout << i << "\n";
    }
}

int main()
{
    int num = getNum();
    getNTable(num);
}
