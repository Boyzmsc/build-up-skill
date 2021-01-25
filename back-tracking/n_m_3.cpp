#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
bool isVisit[8];
int nums[8];

// 함수 외부에서 변수 선언
// Back-Tracking으로 구현 (조건문 + Recursion)
void getSequence(int count)
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

    for (int i = 0; i < n; i++)
    {
        nums[count] = i;
        getSequence(count + 1);
    }
}

int main()
{
    cin >> n >> m;
    getSequence(0);
}