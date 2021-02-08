#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> times;
    vector<int> results;

    for (int i = 0; i < num; i++)
    {
        int time;
        cin >> time;
        times.push_back(time);
    }

    sort(times.begin(), times.end());

    results.push_back(times[0]);

    int result = times[0];

    for (int i = 1; i < times.size(); i++)
    {
        results.push_back(results[i - 1] + times[i]);
        result += results[i];
    }

    cout << result << '\n';
}