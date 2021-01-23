#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// using sort api in C++
void sort(int n)
{
    vector<int> nums;
    while (n--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    sort(n);
}