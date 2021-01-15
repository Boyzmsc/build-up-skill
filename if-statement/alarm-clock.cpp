#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (true)
    {
        if ((a >= 0 && a <= 23) && (b >= 0 && b <= 59))
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if (b >= 45)
    {
        cout << a << " " << b-45 << endl;
    }
    else if (a >= 1 && b < 45)
    {
        cout << a-1 << " " << 60 - (45-b)<< endl;
    }
    else if (a == 0 && b < 45)
    {
        cout << 23 << " " << 60 - (45-b) << endl;
    }
}