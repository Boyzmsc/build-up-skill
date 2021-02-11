#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    long long nums[t]{
        0,
    };
    long long check[t - 1]{
        0,
    };

    for (int i = 0; i < t; i++)
    {
        long long num;
        cin >> num;
        nums[i] = num;
    }

    sort(nums, nums + t);

    for (int i = 0; i < t - 1; i++)
    {
        check[i] = nums[i + 1] - nums[i];
    }

    sort(check, check + t - 1);

    long long gcd = 1;
    long long i = 2;
    while (true)
    {
        if (i > check[t - 2])
        {
            break;
        }
        bool c = true;
        for (int j = 0; j < t - 1; j++)
        {
            if (check[j] % i != 0)
            {
                c = false;
                break;
            }
        }
        if (c)
        {
            for (int j = 0; j < t - 1; j++)
            {
                check[j] /= i;
            }
            gcd *= i;
            continue;
        }
        i++;
    }

    vector<long long> results;

    results.push_back(gcd);

    for (int i = 2; i <= sqrt(gcd); i++)
    {
        if (gcd % i == 0)
        {
            if (i == gcd / i)
            {
                results.push_back(i);
            }
            else
            {
                results.push_back(i);
                results.push_back(gcd / i);
            }
        }
    }

    sort(results.begin(), results.end());

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }
    cout << '\n';
}