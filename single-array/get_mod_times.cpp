#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void getModTimes()
{
    map<int, int> m;

    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        
        while (true)
        {
            if (n <= 1000 && n >= 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if (m.find(n % 42) == m.end())
        {
            m.insert({n % 42, 1});
        }
    }
    cout << m.size() << endl;
}

int main()
{
    getModTimes();
}