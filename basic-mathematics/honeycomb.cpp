#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void getHoneyComb(long a)
{
    int result = 0;
    int add = 0;
    int first = 1;
    int last = 1;
    while (true)
    {
        if (a >= first && a <= last)
        {
            result = add;
            break;
        }
        else
        {
            add++;
            first = last + 1;
            last += 6 * add;
        }
    }
    cout << result + 1 << endl;
}

int main()
{
    long a;
    cin >> a;
    getHoneyComb(a);
}