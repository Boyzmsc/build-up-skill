#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

int getNumOfH(int num)
{
    int count = 0;
    if (num < 100)
    {
        return num;
    }
    else
    {
        count += 99;
        for (int i = 100; i <= num; i++)
        {
            vector<int> array;
            bool isH = true;
            int value = 0;
            string n = to_string(i);
            // cout << n << endl;
            for(int k = 0;k< n.length();k++){
                array.push_back(n[k]-'0');
            }
            for(int l = 0;l < array.size()-1;l++){
                if(l == 0){
                    value = array[l+1]- array[l];
                    // cout << "val : "<< value << endl;
                }else{
                    if(value != (array[l+1] - array[l])){
                        isH = false;
                        break;
                    }
                }
            }
            // cout << isH << endl;
            if(isH){
                count ++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    while(true){
        cin >> n;
        if(n > 0 && n <= 1000){
            break;
        }else{
            continue;
        }
    }
    cout << getNumOfH(n) << endl;
}