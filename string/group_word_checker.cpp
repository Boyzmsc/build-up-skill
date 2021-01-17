#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int getTestCaseNum()
{
    int t;
    while (true)
    {
        cin >> t;
        if (t >= 1 && t <= 100)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return t;
}

void getNumOfGroupWord(int testNum)
{
    int result = 0;
    for (int i = 0; i < testNum; i++)
    {
        string s;
        cin >> s;
        bool isGroupWord = true;
        while (true)
        {
            if (s.length() >= 1 && s.length() <= 100)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        string compare;
        for (int j = 0; j < s.length(); j++)
        {
            if (compare.find(s[j], 0) == string::npos)
            {
                compare += s[j];
            }
            else if ((compare.find(s[j], 0) != string::npos) && compare[compare.length() - 1] == s[j])
            {
                continue;
            }
            else
            {
                isGroupWord = false;
                break;
            }
        }
        if (isGroupWord)
        {
            result++;
        }
    }
    cout << result << endl;
}

int main()
{
    int testCase = getTestCaseNum();
    getNumOfGroupWord(testCase);
}