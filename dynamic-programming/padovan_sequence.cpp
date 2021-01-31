#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

long long arr[101]{
    0,
};

int main()
{
    long t;
    cin >> t;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for (long i = 6; i <= 100; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    while (t--)
    {
        long num;
        cin >> num;
        cout << arr[num] << '\n';
    }
}