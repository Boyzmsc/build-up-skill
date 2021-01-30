#include <stdio.h>
#include <iostream>

using namespace std;

int count[41][2];

// 피보나치 함수를 재귀로 구현 안함
// 배열에 0과 1을 몇번 호출했는지 count 개수를 저장
void fibonacci(int n)
{
    count[0][0] = 1;
    count[0][1] = 0;
    count[1][0] = 0;
    count[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        count[i][0] = count[i - 1][0] + count[i - 2][0];
        count[i][1] = count[i - 1][1] + count[i - 2][1];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fibonacci(n);
        cout << count[n][0] << " " << count[n][1] << '\n';
    }
}