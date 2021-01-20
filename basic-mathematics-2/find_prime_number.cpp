#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

int getTestCaseNum()
{
    int t;
    cin >> t;
    return t;
}

void getNumOfPrime(int testNum)
{
    int res = 0;
    for (int i = 0; i < testNum; i++)
    {
        int n;
        scanf("%d", &n);
        bool isPrime = true;

        if (n == 1)
        {
            continue;
        }
        else
        {
            for (int k = 2; k < n; k++)
            {
                if (n % k == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
        {
            cout << "prime : " << n << endl;
            res++;
        }
    }
    cout << res << endl;
}

int main()
{
    int testCase = getTestCaseNum();
    getNumOfPrime(testCase);
}