#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>

using namespace std;

class Coordinate
{
public:
    int x, y;
    Coordinate(int a, int b)
    {
        x = a;
        y = b;
    }
    // sort_coordinate.cpp 응용
    bool operator < (Coordinate &rhs)
    {
        if (y < rhs.y)
            return true;
        else
        {
            if (y == rhs.y)
                return x < rhs.x;
            else
                return false;
        }
    }
};

void sortCoordinate(int n)
{
    vector<Coordinate> points;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        Coordinate point(x, y);
        points.push_back(point);
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i].x << " " << points[i].y << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    sortCoordinate(n);
}