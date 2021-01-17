#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void getTime(string s)
{
    int time = 0;
    for(int i = 0;i < s.length();i++){
        int number = (int)(s[i] - 'A');
        if(number >= (int)('W'-'A')){
            time += 10;
        }else if(number >= (int)('T'-'A')){
            time += 9;
        }else if(number >= (int)('P'-'A')){
            time += 8;
        }else if(number >= (int)('M'-'A')){
            time += 7;
        }else if(number >= (int)('J'-'A')){
            time += 6;
        }else if(number >= (int)('G'-'A')){
            time += 5;
        }else if(number >= (int)('D'-'A')){
            time += 4;
        }else if(number >= (int)('A'-'A')){
            time += 3;
        }
    }
    cout << time << endl;
    
}
int main()
{
    string dial;
    cin >> dial;
    getTime(dial);
}