#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

long long m = 1000000000;

// 최소 비용으로 주유하여 일직선 도로를 달리는 문제
// 풀이 : 현재 주유소보다 더 작은 주유소가 나올때까지 누적합을 구하면 해결
int main()
{
    int num;
    cin >> num;

    vector<long long> distance;
    long long result = 0;

    for (int i = 0; i < num - 1; i++)
    {
        long long d;
        cin >> d;
        distance.push_back(d);
    }

    for (int i = 0; i < num - 1; i++)
    {
        long long c;
        cin >> c;
        m = min(c, m);
        result += m * distance[i];
    }

    cout << result << '\n';
}