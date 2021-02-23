#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a % c;
    }

    int tmp = power(a, b / 2);
    int rlt = (1LL * tmp * tmp) % c;
    if (b % 2)
    {
        rlt = (1LL * rlt * a) % c;
    }

    return rlt;
}

int main()
{
    cin >> a >> b >> c;
    cout << power(a, b);
}