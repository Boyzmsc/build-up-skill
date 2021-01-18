#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void getBreakEvenPoint(long a, long b, long c)
{
    if (b >= c)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a/(c-b) + 1 << endl;
    }
}

int main()
{
    long a, b, c;
    cin >> a >> b >> c;
    getBreakEvenPoint(a, b, c);
}