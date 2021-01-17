#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void compareNum(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if (stoi(s1) > stoi(s2))
    {
        cout << s1 << endl;
    }
    else
    {
        cout << s2 << endl;
    }
}
int main()
{
    string first, second;
    cin >> first >> second;
    compareNum(first, second);
}