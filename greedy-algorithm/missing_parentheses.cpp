#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> add;
    vector<int> sub;

    bool isMinus = false;
    bool isNum = false;
    int num;
    for (int i = 0; i < s.length(); i++)
    {
        if ((i == s.length() - 1) && isMinus && isNum)
        {
            num = num * 10 + (s[i] - '0');
            sub.push_back(num);
        }
        else if ((i == s.length() - 1) && isMinus && !isNum)
        {
            num = s[i] - '0';
            ;
            sub.push_back(num);
        }
        else if (!isNum && isMinus && s[i] != '+' && s[i] != '-')
        {
            num = s[i] - '0';
            isNum = true;
        }
        else if (isNum && isMinus && s[i] != '+' && s[i] != '-')
        {
            num = num * 10 + (s[i] - '0');
        }
        else if ((s[i] == '-' || s[i] == '+') && isMinus && isNum)
        {
            sub.push_back(num);
            isNum = false;
            num = 0;
        }

        if (i == s.length() - 1 && !isMinus && isNum)
        {
            num = num * 10 + (s[i] - '0');
            add.push_back(num);
        }
        else if (i == s.length() - 1 && !isMinus && !isNum)
        {
            num = s[i] - '0';
            add.push_back(num);
        }
        else if (!isMinus && !isNum && s[i] != '+' && s[i] != '-')
        {
            num = s[i] - '0';
            isNum = true;
        }
        else if (isNum && !isMinus && s[i] != '+' && s[i] != '-')
        {
            num = num * 10 + (s[i] - '0');
        }
        else if ((s[i] == '-' || s[i] == '+') && !isMinus && isNum)
        {
            add.push_back(num);
            isNum = false;
            num = 0;
        }

        if (s[i] == '-')
        {
            isMinus = true;
        }
    }

    int result = 0;
    for (int i = 0; i < add.size(); i++)
    {
        result += add[i];
    }
    for (int i = 0; i < sub.size(); i++)
    {
        result -= sub[i];
    }
    cout << result << '\n';
}