#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int dp[1001][1001]{
    0,
};
int MOD = 10007;

int getBinomial(int a, int b)
{
    if (dp[a][b] != 0)
    {
        return dp[a][b];
    }
    if (a == b || b == 0)
    {
        return 1;
    }
    return dp[a][b] = (getBinomial(a - 1, b) + getBinomial(a - 1, b - 1)) % MOD;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getBinomial(a, b) << '\n';
}