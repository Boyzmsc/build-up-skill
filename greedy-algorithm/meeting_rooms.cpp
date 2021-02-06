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

// 그리디 알고리즘을 이용해 최대로 할 수 있는 회의의 갯수를 출력
// 회의 종료 시간을 기준으로 오름차순으로 정렬한 뒤,
// 마지막 회의 종료 시간과 그 다음 회의 시작 시간을 비교
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

    cout << result << '\n';
}