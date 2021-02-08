#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// 식이 주어졌을 때, 괄호를 적절히 쳐서 나오는 식의 최솟값 구하기
// 풀이 : '-'가 나온 시점부터 그 뒤에 오는 피연산자들을 모두 빼주면 됨
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
        // '-' 연산자가 나온 뒤에 해당하는 조건문
        // input을 문자열로 받기 때문에 char형태의 숫자를 정수 형태로 변환
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

        // '-' 연산자가 나오기 전에 해당하는 조건문
        // input을 문자열로 받기 때문에 char형태의 숫자를 정수 형태로 변환
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

        // '-' 연산자가 나온 시점부턴 뒤에 피연산자들을 전부 뺌
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