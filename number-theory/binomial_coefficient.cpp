#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int result = 1;

    for (int i = 0; i < b; i++)
    {
        result *= a - i;
    }

    for (int i = 0; i < b; i++)
    {
        result /= b - i;
    }

    cout << result << '\n';
}