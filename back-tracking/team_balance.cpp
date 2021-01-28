#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 두 팀의 능력치 차를 담을 백터
vector<int> results;
// 반대 팀을 위한 백터
vector<int> opposite;
// 뽑힌 팀을 위한 백터
vector<int> nums;
// 해당 수가 뽑혔는지 확인하기 위한 배열
bool check[20]{
    false,
};
// 능력치 값을 담은 테이블
int table[20][20];
// 테스트 케이스
int t;

// t/2만큼 인원을 뽑으면 뽑힌 팀의 능력치와 반대 팀의 능력치의 차를 결과값 백터에 담음
// back-tracking으로 모든 경우의 수를 탐색하도록 구현
void dfs(int count, int index)
{
    if (count == t / 2)
    {
        for (int i = 0; i < t; i++)
        {
            if (check[i] == false)
            {
                opposite.push_back(i);
            }
        }
        int result = 0;
        for (int i = 0; i < opposite.size() - 1; i++)
        {
            for (int j = i + 1; j < opposite.size(); j++)
            {
                result += table[opposite[i]][opposite[j]] + table[opposite[j]][opposite[i]];
            }
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                result -= table[nums[i]][nums[j]] + table[nums[j]][nums[i]];
            }
        }
        results.push_back(abs(result));
        opposite.clear();
        return;
    }
    for (int i = index; i <= t / 2 + count; i++)
    {
        nums.push_back(i);
        check[i] = true;
        dfs(count + 1, i + 1);
        // back-tracking 이후 nums백터에 들어간 값과 check배열 초기화
        nums.pop_back();
        check[i] = false;
    }
}

int main(void)
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> table[i][j];
        }
    }
    dfs(0, 0);
    sort(results.begin(), results.end());
    // 뽑힌 팀의 능력치와 반대 팀의 능력치의 차 중 최솟값을 출력
    cout << results[0] << endl;
}