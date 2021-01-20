#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

void getNumOfPrime(int n)
{
    int double_n = n * 2;

    // sieve_of_eratosthenes.cpp 활용
    bool arr_num[double_n + 1]{
        false,
    };
    arr_num[0] = true;
    arr_num[1] = true;
    for (int i = 2; i * i <= double_n; i++)
    {
        if (!arr_num[i])
        {
            for (int j = i * i; j <= double_n; j += i)
            {
                arr_num[j] = true;
            }
        }
    }
    int res = 0;
    for (int i = n + 1; i <= double_n; i++)
    {
        if (!arr_num[i])
        {
            res++;
        }
    }
    cout << res << '\n';
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        else
        {
            getNumOfPrime(n);
        }
    }
}