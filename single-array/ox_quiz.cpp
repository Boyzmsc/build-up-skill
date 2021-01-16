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
    for (int j = 0; j < num; j++)
    {
        string oxQuiz;
        while (true)
        {
            cin >> oxQuiz;
            if (oxQuiz.length() > 0 && oxQuiz.length() < 80)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        int result = 0;
        int score = 1;
        for (int i = 0; i < oxQuiz.length(); i++)
        {
            if (oxQuiz[i] == 'O')
            {
                result += score;
                score++;
            }
            else
            {
                score = 1;
            }
        }
        cout << result << endl;
    }
}

int main()
{
    int n = getTestCase();
    getOXQuiz(n);
}
