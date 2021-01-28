#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> results;
int operators[4];

// 입력받은 operator들을 모든 경우의 수로 계산하는 back-tracking 메서드
// count -> operator들을 모두 참조했는지 확인하기 위한 인자
// num -> back-tracking에서 계산된 값
// plus -> 남아있는 plus operator 개수
// minus -> 남아있는 minus operator 개수
// multi -> 남아있는 multi operator 개수
// divide -> 남아있는 divide operator 개수
void dfs(int count, int num, int plus, int minus, int multi, int divide)
{
    if (count == nums.size() - 1)
    {
        results.push_back(num);
        return;
    }

    if (plus > 0)
    {
        // cout << num << " + " << nums[count+1] << endl;
        dfs(count + 1, num + nums[count + 1], plus - 1, minus, multi, divide);
    }
    if (minus > 0)
    {
        // cout << num << " - " << nums[count+1] << endl;
        dfs(count + 1, num - nums[count + 1], plus, minus - 1, multi, divide);
    }
    if (multi > 0)
    {
        // cout << num << " * " << nums[count+1] << endl;
        dfs(count + 1, num * nums[count + 1], plus, minus, multi - 1, divide);
    }
    if (divide > 0)
    {
        // cout << num << " / " << nums[count+1] << endl;
        dfs(count + 1, num / nums[count + 1], plus, minus, multi, divide - 1);
    }
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    // +, -, *, / 순으로 operators 백터에 insert
    cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

    dfs(0, nums[0], operators[0], operators[1], operators[2], operators[3]);

    sort(results.begin(), results.end());
    cout << results[results.size() - 1] << '\n';
    cout << results[0] << '\n';
}