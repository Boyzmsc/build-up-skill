#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MAX = 26;

int main()
{
    int arr[MAX];
    // 배열 내의 값 지정
    fill_n(arr,MAX,-1);
    string s;
    cin >> s;
    for(int i = 0; i<s.length(); i++){
        if(arr[s[i]-'a'] == -1){
            arr[s[i]-'a'] = i;
        }
    }
    for(int j = 0;j<MAX;j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}