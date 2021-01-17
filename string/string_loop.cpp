#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int getTestCaseNum()
{
    int t;
    while(true){
        cin >> t;
        if(t >= 1 && t <= 1000){
            break;
        }else{
            continue;
        }
    }
    return t;
}

void getRepeatString(int testNum)
{
    for (int i = 0; i < testNum; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        while (true)
        {
            if ((a >= 1 && a <= 8) && (s.length() >= 1 && s.length() <=20))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        for(int i = 0; i< s.length(); i++){
            int count = a;
            while(count--){
                cout << s[i];
            }
        }
        cout << endl;
    }

    
}

int main()
{
    int testCase = getTestCaseNum();
    getRepeatString(testCase);
}