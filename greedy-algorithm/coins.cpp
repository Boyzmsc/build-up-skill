#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int num, value;
    cin >> num >> value;

    int coins[num];

    for (int i = 0; i < num; i++)
    {
        int coin;
        cin >> coin;

        coins[i] = coin;
    }

    sort(coins, coins + num);
    reverse(coins, coins + num);

    int count = 0;
    for (int i = 0; i < num; i++)
    {
        while (coins[i] <= value)
        {
            value -= coins[i];
            count++;
        }
    }
    cout << count << endl;
}