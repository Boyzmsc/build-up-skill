#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void getLessThanX(int num, int x)
{
    vector<int> a;
    for (int j = 0; j < num; j++)
    {
        int n;
        while (1)
        {
            cin >> n;
            if (n >= 1 && n <= 10000)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if (n < x)
        {
            a.push_back(n);
        }
    }
    for(int i = 0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t, x;
    while (true)
    {
        cin >> t >> x;
        if (t >= 1 && x <= 10000)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    getLessThanX(t,x);
}
