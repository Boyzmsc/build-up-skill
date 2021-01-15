#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (true)
    {
        if ((a >= -1000 && a <= 1000 && a != 0) && (b >= -1000 && b <= 1000 && b != 0))
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if (a > 0 && b > 0)
    {
        cout << 1 << endl;
    }
    else if (a > 0 && b < 0)
    {
        cout << 4 << endl;
    }
    else if (a < 0 && b < 0)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}