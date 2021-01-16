#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int input(){
    int a;
    cin >> a ;
    while (true)
    {
        if (a >= 1 && a <= 10000)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return a;
}

void getMultiTable(int num){
    int result = 0;
    for (int i = 1; i<= num; i++){
        result += i;
    }
    cout << result << endl;
}

int main()
{
    int a = input();
    getMultiTable(a);
}
