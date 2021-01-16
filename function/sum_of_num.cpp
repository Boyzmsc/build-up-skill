#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

long sum(vector<int> &a){
    long result = 0;
    for(int i = 0;i< a.size(); i++){
        result += a[i];
    }
    return result;
}
