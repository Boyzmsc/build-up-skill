#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// selection sort
void selectionSort(int n)
{
    vector<int> nums;
    while (n--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] >= nums[j])
            {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    selectionSort(n);
}