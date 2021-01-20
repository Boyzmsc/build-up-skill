#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

void getPrimeNumPartition(int test)
{
    for (int t = 0; t < test; t++)
    {
        int n;
        cin >> n;
        vector<int> first_add;

        // sieve_of_eratosthenes.cpp 활용
        bool arr_num[n + 1]{
            false,
        };
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
        for (int i = 2; i <= n; i++)
        {
            if (!arr_num[i])
            {
                first_add.push_back(i);
            }
        }

        // prime number partition 구하기
        multimap<int, string> add;
        multimap<int, string>::iterator iter;
        for (int i = 0; i < first_add.size(); i++)
        {
            for (int j = i; j < first_add.size(); j++)
            {
                if (first_add[i] + first_add[j] == n)
                {
                    string s;
                    add.insert({abs(first_add[i] - first_add[j]), (to_string(first_add[i]) + " " + to_string(first_add[j]))});
                }
            }
        }
        cout << add.begin()->second << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    getPrimeNumPartition(t);
}