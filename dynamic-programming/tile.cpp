#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int len;
    cin >> len;
    int cases[len + 1];
    cases[0] = 1;
    cases[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        cases[i] = (cases[i - 1] + cases[i - 2]) % 15746;
    }
    cout << cases[len] << '\n';
}