#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a;
    while (true)
    {
        cin >> a;
        if (a >= 0 && a <= 100)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if (a >= 90)
    {
        cout << "A" << endl;
    }
    else if (a >= 80)
    {
        cout << "B" << endl;
    }else if (a >= 70)
    {
        cout << "C" << endl;
    }else if (a >= 60)
    {
        cout << "D" << endl;
    }else
    {
        cout << "F" << endl;
    }
}