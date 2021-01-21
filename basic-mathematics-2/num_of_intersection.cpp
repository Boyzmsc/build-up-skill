#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

int getNumOfPoint(int x1, int y1, int r1, int x2, int y2, int r2)
{
    int big_r, small_r;
    if (r2 >= r1)
    {
        big_r = r2;
        small_r = r1;
    }
    else
    {
        big_r = r1;
        small_r = r2;
    }

    double len = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (len == 0 && big_r == small_r)
    {
        return -1;
    }

    if (len > big_r + small_r)
    {
        return 0;
    }
    else if (len == big_r + small_r)
    {
        return 1;
    }
    else if (len > big_r - small_r && len < big_r + small_r)
    {
        return 2;
    }
    else if (len == big_r - small_r)
    {
        return 1;
    }
    else if (len < big_r - small_r)
    {
        return 0;
    }
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int res = getNumOfPoint(x1, y1, r1, x2, y2, r2);
        cout << res << '\n';
    }
}