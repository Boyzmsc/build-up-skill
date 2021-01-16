#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int input(){
    int a;
    cin >> a ;
    while (true)
    {
        if (a >= 1 && a <= 9)
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
    for (int i = 1; i<= 9; i++){
        cout << num << " * " << i << " = " << num*i << endl;
    }
}

int main()
{
    int a = input();
    getMultiTable(a);
}
