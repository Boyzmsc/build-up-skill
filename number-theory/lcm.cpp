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
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        int big, small;

        if (n1 >= n2)
        {
            big = n1;
            small = n2;
        }
        else
        {
            big = n2;
            small = n1;
        }

        int gcd = 1;
        int lcm = 1;

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

        lcm = (n1 / gcd) * (n2 / gcd) * gcd;

        cout << lcm << '\n';
    }
}