#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> results;
vector<int> opposite;
vector<int> nums;
bool check[20]{
    false,
};
int table[20][20];
int t;

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
                // cout << opposite[i] << " " << opposite[j] << endl;
                result += table[opposite[i]][opposite[j]] + table[opposite[j]][opposite[i]];
            }
        }
        // cout << "before " << result << endl;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                // cout << nums[i] << " " << nums[j] << endl;
                result -= table[nums[i]][nums[j]] + table[nums[j]][nums[i]];
            }
        }
        // cout << "after " << result << endl;
        results.push_back(abs(result));
        opposite.clear();
        // cout << "---------------" << endl;
        return;
    }
    for (int i = index; i <= t / 2 + count; i++)
    {
        nums.push_back(i);
        check[i] = true;
        dfs(count + 1, i + 1);
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
    // for (int i = 0; i < results.size(); i++)
    // {
    //     cout << results[i] << " ";
    // }
    // cout << endl;
    cout << results[0] << endl;
}