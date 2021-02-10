#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> nums;
    int result;
    for (int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }
    sort(nums.begin(), nums.end());

    if (num % 2 == 0)
    {
        result = nums[0] * nums[num - 1];
    }
    else
    {
        result = nums[num / 2] * nums[num / 2];
    }

    cout << result << '\n';
}