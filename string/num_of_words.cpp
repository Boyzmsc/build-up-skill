#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MAX = 26;

void getNumOfWords(string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // 공백을 의미하는 아스키 코드 = 32
        if ((int)s[i] == 32)
        {
            result++;
        }
    }
    if (((int)s[0] == 32) && (int)s[s.length()-1] == 32)
    {
        cout << result - 1 << endl;
    }
    else if((((int)s[0] == 32) || (int)s[s.length()-1] == 32))
    {
        cout << result << endl;
    }else{
        cout << result + 1 << endl;
    }
}

int main()
{
    char input[1000000];
    // 공백을 포함한 입력 받기 -> cin.getline() 사용!
    cin.getline(input, sizeof(input));
    getNumOfWords(input);
}