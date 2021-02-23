#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

long long a, b;
long long MOD = 1000000007LL;
long long factorial[4000001], inverse[4000001];

// 분할 정복을 사용한 거듭제곱과 페르마의 소정리를 이용해 
// 곱셈의 역원을 구함
long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a % MOD;
    }

    int tmp = power(a, b / 2);
    int rlt = (1LL * tmp * tmp) % MOD;

    if (b % 2)
    {
        rlt = (1LL * rlt * a) % MOD;
    }

    return rlt;
}

int main()
{
    cin >> a >> b;

    // 팩토리얼 (!)
    factorial[1] = 1;
    for (int i = 2; i <= 4000000; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    inverse[4000000] = power(factorial[4000000], MOD - 2);

    for (int i = 3999999; i >= 1; i--)
    {
        inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;
    }

    if (a == b || b == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        long long rlt = (factorial[a] * inverse[b]) % MOD;
        rlt = (rlt * inverse[a - b]) % MOD;
        cout << rlt << endl;
    }
}