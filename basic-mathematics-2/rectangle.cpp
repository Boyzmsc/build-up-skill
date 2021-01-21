#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

void getMinDistance(int x, int y, int w, int h)
{
    vector<int> diff = {w - x, h - y, x - 0, y - 0};
    sort(diff.begin(),diff.end());
    cout << diff[0] << '\n';
}

int main()
{
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    getMinDistance(x, y, w, h);
}