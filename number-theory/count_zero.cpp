#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    cout << (num / 5) + (num / 25) + (num / 125) << '\n';
}