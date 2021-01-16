#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int getTestCase()
{
    int t;
    cin >> t;
    while (true)
    {
        if (t <= 1000)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return t;
}

void getOXQuiz(int num)
{
    for (int t = 0; t < num; t++)
    {
        int personNum;
        while (true)
        {
            cin >> personNum;
            if (personNum >= 1 && personNum <= 1000)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        double sum = 0;
        vector<int> scores;
        for (int j = 0; j < personNum; j++)
        {
            int score;
            while (true)
            {
                cin >> score;
                if (score >= 0 && score <= 100)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            sum += score;
            scores.push_back(score);
        }
        double count = 0;
        double average = sum / scores.size();
        for (int k = 0; k < scores.size(); k++)
        {
            if (scores[k] > average)
            {
                count++;
            }
        }
        // 소수점 아래 자릿수 설정
        cout << fixed;
        cout.precision(3);
        cout << (count / scores.size()) * 100 << "%" << endl;
    }
}

int main()
{
    int n = getTestCase();
    getOXQuiz(n);
}