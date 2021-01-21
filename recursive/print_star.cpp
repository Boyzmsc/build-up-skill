#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <math.h>
using namespace std;

char star_map[2187][2187];

void printStar(int x, int y, int n)
{
    if (n == 1)
    {
        star_map[x][y] = '*';
        return;
    }

    int next = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {
                ;
            }
            else
            {
                printStar(x + (i * next), y + (j * next), next);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            star_map[i][j] = ' ';
        }
    }

    printStar(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << star_map[i][j];
        }
        cout << '\n';
    }
}