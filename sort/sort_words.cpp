#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>

using namespace std;

bool compareWords(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        // 사전 순으로 비교
        return a < b;
    }
}

void sortWords(int n)
{
    int N = n;
    string words[20000];
    int index = 0;
    while (N--)
    {
        string word;
        cin >> word;
        words[index] = word;
        index++;
    }

    // sort 함수 세번째 인자에 비교 함수를 넣어줌으로써
    // 해당 함수의 정의된 조건을 기준으로 정렬
    sort(words, words + n, compareWords);

    for (int i = 0; i < n; i++)
    {
        if (words[i] == words[i - 1] && i != 0)
        {
            continue;
        }
        else
        {
            cout << words[i] << '\n';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sortWords(n);
}