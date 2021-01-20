#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

void getPrimeNumber(int m, int n)
{
    bool isFirst = true;
    int first;
    int res = 0;
    for (int i = m; i <= n; i++)
    {
        bool isPrime = true;

        if (i == 1)
        {
            continue;
        }
        else
        {
            for (int k = 2; k < i; k++)
            {
                if (i % k == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
        {
            cout << "prime : " << i << endl;
            res += i;
        }

        if (isPrime && isFirst)
        {
            first = i;
            isFirst = false;
        }
    }
    if (res == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
        cout << first << endl;
    }
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    getPrimeNumber(m, n);
}