#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

void getPrimeNumber(int m, int n)
{
    // true -> 소수 아님, false -> 소수
    bool arr_num[n + 1]{false,};
    arr_num[0] = true;
    arr_num[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (!arr_num[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr_num[j] = true;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (!arr_num[i])
        {
            cout << i << '\n';
        }
    }
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    getPrimeNumber(m, n);
}