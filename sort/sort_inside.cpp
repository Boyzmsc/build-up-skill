#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void sortInside(string s)
{
    vector<int> nums;
    for (int i = 0; i < s.length(); i++)
    {
        nums.push_back(s[i]-'0');
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    sortInside(s);
}