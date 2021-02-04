#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pos;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        pos.push_back({start, end});
    }

    // pos의 원소 중 첫번째 인자를 기준으로 정렬
    sort(pos.begin(), pos.end());

    // index가 1부터 벡터 끝까지 길이가 가장 긴
    // 증가하는 수열(첫번째 인자, 두번째 인자)을 dp에 저장
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pos[j].first < pos[i].first && pos[j].second < pos[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 전체 개수에서 dp의 원소들 중 가장 큰 원소를 뺀 값 리턴
    cout << n - *max_element(dp.begin(), dp.end()) << "\n";
}