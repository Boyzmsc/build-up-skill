#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// "00"과 "1" 타일을 이용해 주어진 길이에 대한 경우의 수를 구하는 문제
// 순서대로 길이가 1,2,3,4,5...에 대한 경우의 수를 구하자면
// 경우의 수가 피보나치 수열의 형태를 띄움
int main()
{
    int len;
    cin >> len;
    int cases[len + 1];
    cases[0] = 1;
    cases[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        cases[i] = (cases[i - 1] + cases[i - 2]) % 15746;
    }
    cout << cases[len] << '\n';
}