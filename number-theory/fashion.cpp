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
        int n;
        cin >> n;
        vector<pair<string, int>> kinds;
        while (n--)
        {
            string name, kind;
            cin >> name >> kind;
            if (kinds.size() == 0)
            {
                kinds.push_back({kind, 1});
            }
            else
            {
                bool has = false;
                for (int i = 0; i < kinds.size(); i++)
                {
                    if (kind == kinds[i].first)
                    {
                        kinds[i].second++;
                        has = true;
                        break;
                    }
                }
                if (!has)
                {
                    kinds.push_back({kind, 1});
                }
            }
        }
        int result = 1;
        for (int i = 0; i < kinds.size(); i++)
        {
            result *= kinds[i].second + 1;
        }
        cout << result - 1 << endl;
    }
}