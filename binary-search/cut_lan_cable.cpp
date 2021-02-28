#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int k;
ll cables[10000];
ll m = 0;

bool check(ll mid)
{
    ll check = 0;
    for (int i = 0; i < n; i++)
    {
        check += cables[i] / mid;
    }
    return (check >= k);
}

ll binarySearch(ll start, ll end)
{
    ll mid = (start + end) / 2;
    ll rlt;

    if (start > end)
    {
        return m;
    }

    if (check(mid))
    {
        rlt = max(binarySearch(mid + 1, end), max(m, mid));
    }
    else
    {
        rlt = binarySearch(start, mid - 1);
    }

    return rlt;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &cables[i]);
    }

    ll end = LLONG_MAX;

    printf("%lld\n", binarySearch(0, end));
}