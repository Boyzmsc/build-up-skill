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
    // sort 함수를 위한 < 연산자 재정의
    // sort 함수에 재정의된 조건으로 적용됨
    bool operator < (Coordinate &rhs)
    {
        if (x < rhs.x)
            return true;
        else
        {
            if (x == rhs.x)
                return y < rhs.y;
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