#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    while (true)
    {
        if (a >= 1 && a <= 4000)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    if (((a % 100 != 0) && (a % 4 == 0)) || (a % 400 == 0))
    {
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}