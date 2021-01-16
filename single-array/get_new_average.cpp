#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int getTestCase()
{
    int a;
    cin >> a;
    while (true)
    {
        if (a <= 1000)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return a;
}

void getNewAverage(int num)
{
    vector<double> scores;
    for (int i =1;i <= num; i++)
    {
        int score;
        cin >> score;
        while (true)
        {
            if (score >= 0 && score <= 100)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        scores.push_back(score);
    }
    sort(scores.begin(), scores.end());
    double sum = 0;
    for (int j = 0; j < scores.size(); j++)
    {
        sum += (scores[j] / (scores[scores.size() - 1])) * 100;
    }

    double average = sum / scores.size();

    cout << average << endl;
}

int main()
{
    int n = getTestCase();
    getNewAverage(n);
}
