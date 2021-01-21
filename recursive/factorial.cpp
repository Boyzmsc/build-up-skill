#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

int factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << '\n';
}