#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

long dp[31][31]{
    0,
};

long getBinomial(int n, int m)
{
    if (dp[n][m] != 0)
    {
        return dp[n][m];
    }
    if (n == m || m == 0)
    {
        return 1;
    }
    return dp[n][m] = getBinomial(n - 1, m) + getBinomial(n - 1, m - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << getBinomial(m, n) << '\n';
    }
}