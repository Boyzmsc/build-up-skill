#include <stdio.h>
#include <iostream>

using namespace std;

int arr[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    // arr이라는 배열에 인자값들을 저장함으로써,
    // 추후에 해당 인자값을 재계산할 필요 없이, 
    // 배열에서 바로 결과값을 가져오면 됨
    // memoization을 이용한 시간 단축!
    if (arr[a][b][c] != 0)
    {
        return arr[a][b][c];
    }
    if (a < b && b < c)
    {
        arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return arr[a][b][c];
}

int main()
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::ios_base::sync_with_stdio(false);

    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        else
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
        }
    }
}