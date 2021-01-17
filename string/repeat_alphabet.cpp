#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MAX = 26;

void getAlphabet(string s)
{
    int arr_alphabet[MAX];
    // 배열 내의 값 지정
    fill_n(arr_alphabet, MAX, 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            arr_alphabet[s[i] + 32 - 'a']++;
        }
        else
        {
            arr_alphabet[s[i] - 'a']++;
        }
    }
    // for (int j = 0; j < MAX; j++)
    // {
    //     cout << arr_alphabet[j] << " ";
    // }
    // cout << endl;

    int max_index = 0;
    bool isRepeat = false;
    for (int j = 0; j < MAX; j++)
    {
        if (arr_alphabet[max_index] < arr_alphabet[j])
        {
            max_index = j;
            isRepeat = false;
        }
        else if ((arr_alphabet[max_index] == arr_alphabet[j]) && j > 0)
        {
            isRepeat = true;
        }
    }
    if (isRepeat)
    {
        cout << "?" << endl;
    }
    else
    {
        cout << (char)(max_index + 'a' - 32) << endl;
    }
}

int main()
{

    string s;
    while (true)
    {
        cin >> s;
        if (s.length() >= 1 && s.length() <= 1000000)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    getAlphabet(s);
}