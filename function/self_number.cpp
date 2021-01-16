#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int getNumDigit(int num){
    int digit = 0;
    while(num >= 10){
        digit ++;
        num = num / 10;
    }
    return digit;
}

int d(int num){
    int digit = getNumDigit(num);
    int result = num;
    while(digit > 0){
        result += num / (int)pow(10,digit);
        num = num % (int)pow(10,digit);
        digit--;
    }
    result += num;
    return result;
}

void getSelfNumber(){
    map<int,int> a;
    map<int,int>::iterator iter;
    for(int i = 1;i<=10000;i++){
        a.insert({i,i});
    }
    for(int i = 1;i<=10000;i++){
        int start = i;
        while(start <= 10000){
            start = d(start);
            a.erase(start);
        }
    }
    for(iter = a.begin();iter != a.end();iter++){
        cout << iter->first << endl;
    }
}

int main(){
    getSelfNumber();
}