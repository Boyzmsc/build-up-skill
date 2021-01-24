#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

// using sort api in C++
void sort(int n)
{
    vector<int> nums;
    vector<int> mode;
    int count[8001]{
        0,
    };
    while (n--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    double sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        count[nums[i] + 4000]++;
    }
    // round() -> 반올림 함수
    sum /= nums.size();
    cout << round(sum) << '\n';

    cout << nums[nums.size() / 2] << '\n';

    int compare = count[0];
    for (int i = 0; i < 8001; i++)
    {
        if (compare < count[i])
        {
            compare = count[i];
            mode.erase(mode.begin(), mode.end());
            mode.push_back(i - 4000);
        }
        else if (compare == count[i])
        {
            mode.push_back(i - 4000);
        }
    }

    sort(mode.begin(), mode.end());

    // for (int i = 0; i < mode.size(); i++)
    // {
    //     cout << mode[i] << endl;
    // }

    // cout << "-------------------" << endl;

    if (mode.size() > 1)
    {
        cout << mode[1] << '\n';
    }
    else
    {
        cout << mode[0] << '\n';
    }

    cout << nums.back() - nums.front() << '\n';
}

int main()
{
    int n;
    cin >> n;
    sort(n);
}