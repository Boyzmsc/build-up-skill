#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

void getArea(int radius)
{
    // Euclidean geometry
    cout << M_PI * radius * radius << '\n';
    // taxi cab geometry
    cout << 2 * radius * radius << '\n';
}

int main()
{
    cout << fixed;
    cout.precision(6);
    int radius;
    cin >> radius;
    getArea(radius);
}