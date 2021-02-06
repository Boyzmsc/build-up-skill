#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Meeting
{
public:
    int start, end;
    Meeting(int s, int e)
    {
        start = s;
        end = e;
    }
    // sort 함수를 위한 < 연산자 재정의
    // sort 함수에 재정의된 조건으로 적용됨
    bool operator<(Meeting &rhs)
    {
        if (end < rhs.end)
            return true;
        else
        {
            if (end == rhs.end)
                return start < rhs.start;
            else
                return false;
        }
    }
};

int main()
{
    int num;
    cin >> num;

    vector<Meeting> meetings;
    int result = 0;

    for (int i = 0; i < num; i++)
    {
        int start, end;
        cin >> start >> end;
        Meeting m(start, end);
        meetings.push_back(m);
    }

    sort(meetings.begin(), meetings.end());

    int last = 0;
    for (int i = 0; i < meetings.size(); i++)
    {
        if (last <= meetings[i].start)
        {
            last = meetings[i].end;
            result++;
        }
    }

    for (int i = 0; i < meetings.size(); i++)
    {
        cout << meetings[i].start << " " << meetings[i].end << endl;
    }

    cout << result << '\n';
}