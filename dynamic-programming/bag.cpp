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

    int dp[capacity + 1]{
        0,
    };

    for (int i = 0; i < num; i++)
    {
        int weight, value;
        cin >> weight >> value;

        // 물건의 무게와 가치를 입력받을 때마다,
        // 최대 무게부터 입력받은 무게까지 각 배낭의 무게에 따라
        // 수용할 수 있는 가치의 최댓값을 dp에 담고있음!
        for (int j = capacity; j >= weight; j--)
        {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    cout << dp[capacity] << endl;
}