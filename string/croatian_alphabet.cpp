#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

string getRepeat(string s, int n){
    string result;
    for(int i = 0;i<n;i++){
        result += s;
    }
    return result;
}

void getNumOfCroatian(string s)
{
    int result = 0;
    string croatian_alphabet[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    for (int i = 0; i < 8; i++)
    {
        auto it = 0;
        while ((it = s.find(croatian_alphabet[i],0)) != string::npos)
        {
            string replaceStr = getRepeat("?",croatian_alphabet[i].length());
            s.replace(it,croatian_alphabet[i].length(),replaceStr);
            it += croatian_alphabet[i].length();
            result ++;
        }
    }
    for(int j = 0;j< s.length();j++){
        if(s[j] == '?'){
            continue;
        }else{
            result++;
        }
    }
    // cout << s << endl;
    cout << result << endl;
}
int main()
{
    string alphabet;
    cin >> alphabet;
    getNumOfCroatian(alphabet);
}