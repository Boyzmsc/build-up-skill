#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

void getNumOfBag(int a)
{
    map<int, int> arr_five;
    map<int, int> arr_three;
    map<int, int> sum;
    map<int, int>::iterator iter;
    map<int, int>::iterator iter2;
    bool isExist = false;

    for (int i = 0; i < a / 5 + 1; i++)
    {
        arr_five[5 * i] = i;
    }

    for (int i = 0; i < a / 3 + 1; i++)
    {
        arr_three[3 * i] = i;
    }

    for (iter = arr_five.begin(); iter != arr_five.end(); iter++)
    {
        for (iter2 = arr_three.begin(); iter2 != arr_three.end(); iter2++)
        {
            sum[iter->first + iter2->first] = iter->second + iter2->second;
        }
    }

    sum.insert(arr_five.begin(), arr_five.end());
    sum.insert(arr_three.begin()++, arr_three.end());

    for (iter = sum.begin(); iter != sum.end(); iter++)
    {
        // cout << "key : " << iter->first << " value : " << iter->second << endl;
        if (a == iter->first)
        {
            isExist = true;
            cout << iter->second << endl;
            break;
        }
    }
    if (!isExist)
    {
        cout << -1 << endl;
    }
}

int main()
{
    int a;
    cin >> a;
    getNumOfBag(a);
}