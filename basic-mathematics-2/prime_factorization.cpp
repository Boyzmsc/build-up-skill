#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

void getNumOfPrime(int n)
{
    // 2부터 시작해서 n의 제곱근까지 나눠지는 소수를 구함
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
            n /= i;
        }
        else
        {
            i++;
        }
    }
    if (n != 1)
    {
        printf("%d\n", n);
    }

    // 답은 맞지만 시간 초과 발생
    // vector<int> primes;
    // bool isFirst = true;
    // int first;
    // int res = 0;
    // cout <<(int)sqrt(n) << endl;
    // for (int i = 2; i <= (int)sqrt(n) + 1; i++)
    // {
    //     bool isPrime = true;

    //     for (int k = 2; k < i; k++)
    //     {
    //         if (i % k == 0)
    //         {
    //             isPrime = false;
    //             break;
    //         }
    //     }

    //     if (isPrime)
    //     {
    //         // cout << "prime : " << i << endl;
    //         primes.push_back(i);
    //     }
    // }

    // int index = 0;
    // int divide = primes[index];

    // while (n != 1)
    // {
    //     if (n % divide == 0)
    //     {
    //         cout << divide << endl;
    //         n /= divide;
    //     }
    //     else
    //     {
    //         index++;
    //         divide = primes[index];
    //     }
    // }
}

int main()
{
    int n;
    scanf("%d", &n);
    getNumOfPrime(n);
}