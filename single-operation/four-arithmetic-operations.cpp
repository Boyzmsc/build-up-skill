#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(1){    
        cin>>a>>b;        
        if(a > 0 && b <= 10000 && b != 0)
            break;
        else
            continue;
    }
    cout.precision(15);
    cout << a+b << endl;
    cout << a-b << endl;
    cout << a*b << endl;
    cout << a/b << endl;
    cout << a % b << endl;
}