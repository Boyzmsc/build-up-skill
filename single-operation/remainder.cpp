#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    while(1){    
        cin>>a>>b>>c;        
        if((a >= 2 && a <= 10000) && (b >= 2 && b <= 10000) && (c >= 2 && c <= 10000))
            break;
        else
            continue;
    }
    cout.precision(15);
    cout << (a+b)%c << endl;
    cout << ((a%c)+(b%c))%c << endl;
    cout << (a*b)%c << endl;
    cout << ((a%c)*(b%c))%c << endl;
}