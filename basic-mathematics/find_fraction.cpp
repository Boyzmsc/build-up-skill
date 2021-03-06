#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void findFraction(long a)
{
    string result;
    int add = 1;
    int first = 1;
    int last = 1;
    int count = 0;
    while (true)
    {
        if (a >= first && a <= last)
        {
            count = add;
            break;
        }
        else
        {
            add++;
            first = last + 1;
            last += add;
        }
        // cout << "f : " << first << " e : " << last << endl;
    }
    // a - first => 번째 수
    // cout << count << endl;
    if (count % 2 == 1)
    {
        cout << count - (a - first) << "/" << 1 + (a - first) << endl;
    }
    else
    {
        cout << 1 + (a - first) << "/" << count - (a - first) << endl;
    }
}

int main()
{
    long a;
    cin >> a;
    findFraction(a);
}