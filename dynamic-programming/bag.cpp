#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int num, capacity;
    cin >> num >> capacity;

    // pair : weight, value
    vector<pair<int, int>> items;
    int dp[capacity + 1]{
        0,
    };

    for (int i = 0; i < num; i++)
    {
        int weight, value;
        cin >> weight >> value;

        for (int j = capacity; j >= weight; j--)
        {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    cout << dp[capacity] << endl;
}