#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void getNumTimes()
{
    map<int, int> m;
    int a, b, c;
    cin >> a >> b >> c;

    while (true)
    {
        if ((a >= 100 && a < 1000) && (b >= 100 && b < 1000) && (c >= 100 && c < 1000))
        {
            break;
        }
        else
        {
            continue;
        }
    }

    int num = a * b * c;

    for (int i = 0; i < 10; i++)
    {
        m.insert({i, 0});
    }

    while (num > 10)
    {
        m[num % 10]++;
        num = num / 10;
    }
    m[num]++;

    for (int i = 0; i < 10; i++)
    {
        cout << m[i] << endl;
    }
}

int main()
{
    getNumTimes();
}