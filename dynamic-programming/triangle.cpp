#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    int arr[n + 1][n + 1];
    vector<int> results;
    for (int i = 1; i <= n; i++)
    {
        arr[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int num;
            cin >> num;
            if (j == 1)
            {
                arr[i][1] = num + arr[i - 1][1];
            }
            else if (j == i)
            {
                arr[i][i] = num + arr[i - 1][i - 1];
            }
            else
            {
                arr[i][j] = num + max(arr[i - 1][j - 1], arr[i - 1][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        results.push_back(arr[n][i]);
    }
    sort(results.begin(), results.end());
    cout << results[results.size() - 1] << '\n';
}