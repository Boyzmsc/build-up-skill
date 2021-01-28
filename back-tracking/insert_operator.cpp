#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int result;
vector<int> nums;
vector<int> results;
int operators[4];

int factorial(int num)
{
    if (num == 0 && num == 1)
    {
        return 1;
    }
    int result = 1;
    for (int i = 2; i < num; i++)
    {
        result *= i;
    }
    return result;
}

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
    cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

    dfs(0, nums[0], operators[0], operators[1], operators[2], operators[3]);

    sort(results.begin(), results.end());
    cout << results[results.size() - 1] << '\n';
    cout << results[0] << '\n';
}