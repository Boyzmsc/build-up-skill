#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int m_r;
    cin >> m_r;
    t--;
    while (t--)
    {
        int n;
        cin >> n;

        int big, small;
        if (m_r >= n)
        {
            big = m_r;
            small = n;
        }
        else
        {
            big = n;
            small = m_r;
        }

        int gcd = 1;
        int i = 2;
        while (true)
        {
            if (i > big)
            {
                break;
            }
            if (big % i == 0 && small % i == 0)
            {
                big /= i;
                small /= i;
                gcd *= i;
                continue;
            }
            i++;
        }

        cout << m_r / gcd << "/" << n / gcd << '\n';
    }
}