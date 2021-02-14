#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

pair<long long, long long> count(long long n)
{
    long long two = 0;
    long long five = 0;

    for (long long i = 2; i <= n; i *= 2)
    {
        two += n / i;
    }

    for (long long i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }

    return make_pair(two, five);
}

int main()
{
    long long n, m;
    cin >> n >> m;

    pair<long long, long long> count_n = count(n);
    pair<long long, long long> count_m = count(m);
    pair<long long, long long> count_n_m = count(n - m);

    long long x = count_n.first - (count_m.first + count_n_m.first);
    long long y = count_n.second - (count_m.second + count_n_m.second);

    if (x < y)
    {
        cout << x << endl;
    }
    else
    {
        cout << y << endl;
    }

    return 0;
}