#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (true)
    {
        if ((a >= -10000 && a <= 10000) && (b >= -10000 && b <= 10000))
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if (a > b)
    {
        cout << ">" << endl;
    }
    else if (a < b)
    {
        cout << "<" << endl;
    }else{
        cout << "==" << endl;
    }
}