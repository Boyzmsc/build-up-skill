#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getPlusTable()
{
    int a, b;
    while (cin >> a >> b)
    {
        while (true)
        {
            if ((a > 0) && (b < 10))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        cout << a + b << endl;
    }
}

int main()
{
    getPlusTable();
}
