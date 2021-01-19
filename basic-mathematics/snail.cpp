#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void getHoneyComb(long a, long b, long v)
{
    long day = 0;

    // long height = 0;
    // while (true)
    // {
    //     day++;
    //     height += a;
    //     if (height >= v)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         height -= b;
    //     }
    // }

    day = (v - a) / (a - b);

    if ((v - a) > (a - b))
    {
        if (day * (a - b) + a < v)
        {
            day++;
        }
    }
    
    if (day == 0 && v > a)
    {
        day++;
    }
    
    cout << ++day << endl;
}

int main()
{
    long a, b, v;
    cin >> a >> b >> v;
    getHoneyComb(a, b, v);
}