#include <bits/stdc++.h>
using namespace std;

// Closest Pair of Points
class Point
{
public:
    int x, y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    bool operator<(Point &rhs)
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

vector<Point> p;
int MAX = 800000000;

int getDistance(Point p1, Point p2)
{
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;
    return (x * x) + (y * y);
}

int solve(int start, int end)
{
    int rlt = MAX;
    if (end - start <= 3)
    {
        for (int i = start; i <= end - 1; i++)
        {
            for (int j = i + 1; j <= end; j++)
            {
                rlt = min(rlt, getDistance(p[i], p[j]));
            }
        }
    }
    else
    {
        int mid = (start + end) / 2;
        int leftMin = solve(start, mid - 1);
        int rightMin = solve(mid + 1, end);

        rlt = min(leftMin, rightMin);

        vector<Point> tmp;

        // 중앙에 있는 점 추가
        Point midPoint(p[mid].y, p[mid].x);
        tmp.push_back(midPoint);

        for (int i = mid - 1; i >= start; i--)
        {
            if (getDistance(Point(p[i].x, 0), Point(p[mid].x, 0)) > rlt)
            {
                break;
            }
            tmp.push_back(Point(p[i].y, p[i].x));
        }

        for (int i = mid + 1; i <= end; i++)
        {
            if (getDistance(Point(p[i].x, 0), Point(p[mid].x, 0)) > rlt)
            {
                break;
            }
            tmp.push_back(Point(p[i].y, p[i].x));
        }

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < tmp.size() - 1; i++)
        {
            for (int j = i + 1; j < tmp.size(); j++)
            {
                if (pow(tmp[i].x - tmp[j].x, 2) >= rlt)
                {
                    break;
                }
                rlt = min(rlt, getDistance(tmp[i], tmp[j]));
            }
        }
    }
    return rlt;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        Point point(x, y);
        p.push_back(point);
    }

    sort(p.begin(), p.end());

    cout << solve(0, p.size() - 1) << '\n';
}