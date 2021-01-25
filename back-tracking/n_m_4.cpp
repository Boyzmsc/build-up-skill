#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
int nums[8];

// 함수 외부에서 변수 선언
// Back-Tracking으로 구현 (조건문 + Recursion)
// 비내림차순을 만족하는 수열 생성
// 비내림차순 - 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족
void getSequence(int count, int index)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << nums[i] + 1 << " ";
        }
        cout << '\n';
        return ;
    }

    for (int i = index; i < n; i++)
    {
        nums[count] = i;
        getSequence(count + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    getSequence(0, 0);
}