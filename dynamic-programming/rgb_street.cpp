#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
int arr[1001][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int red, green, blue;
        cin >> red >> green >> blue;
        arr[i + 1][0] = red + min(arr[i][1], arr[i][2]);
        arr[i + 1][1] = green + min(arr[i][0], arr[i][2]);
        arr[i + 1][2] = blue + min(arr[i][0], arr[i][1]);
    }
    cout << min(arr[n][0], min(arr[n][1], arr[n][2])) << '\n';
}