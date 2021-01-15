#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int third = b / 100;
    int second = (b-third*100) / 10;
    int first = (b-third*100-second*10);
    cout << a * first << endl;
    cout << a * second << endl;
    cout << a * third << endl;
    cout << a * b << endl;
}