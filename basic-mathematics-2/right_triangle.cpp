#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

void isRightTriangle()
{
    int len[3];
    while (true)
    {
        cin >> len[0] >> len[1] >> len[2];
        if (len[0] == 0 && len[1] == 0 && len[2] == 0)
        {
            break;
        }
        sort(len, len + 3);
        
        // for(int i = 0; i< 3 ;i++){
        //     cout << pow(len[i],2) << endl;
        // }

        if ((len[0]*len[0]) + (len[1]*len[1]) == len[2]*len[2])
        {
            cout << "right" << '\n';
        }
        else
        {
            cout << "wrong" << '\n';
        }
    }
}

int main()
{
    isRightTriangle();
}