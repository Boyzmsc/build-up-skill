#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int decomposition(int n)
{
    bool has = false;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        vector<int> dec;
        int pos = 1, num_len = 0;
        while (i >= pos)
        {
            pos *= 10;
            num_len++;
        }
        pos /= 10;
        int getN = i;
        for (int j = 0; j < num_len; j++)
        {
            while (pos >= 1)
            {
                dec.push_back(getN / pos);
                getN %= pos;
                pos /= 10;
            }
        }
        for (int w = 0; w < dec.size(); w++)
        {
            sum += dec[w];
        }
        sum += i;
        // cout << sum << '\n';
        if(sum == n){
            return i;
        }
    }
    if(has == false){
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << decomposition(n) << '\n';
}