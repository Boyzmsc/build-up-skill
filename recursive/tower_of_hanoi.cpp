#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

void hanoi(int n, int start, int pass, int to)
{
    if (n == 1)
    {
        cout << start << " " << to << '\n';
    }
    else
    {
        hanoi(n - 1, start, to, pass);
        cout << start << " " << to << '\n';
        hanoi(n - 1, pass, start, to);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (int)(pow(2, n)) - 1 << '\n';
    hanoi(n, 1, 2, 3);
}