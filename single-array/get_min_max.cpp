#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int getTestCaseNum()
{
    int t;
    while(true){
        cin >> t;
        if(t >= 1 && t <= 1000000){
            break;
        }else{
            continue;
        }
    }
    return t;
}

void getMinMax(int testNum)
{
    vector<int> array;
    for (int i = 0; i < testNum; i++)
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a >= -1000000 && a <= 1000000)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        array.push_back(a);
    }
    sort(array.begin(), array.end());
    cout << array[0] << " " << array[array.size()-1] << endl;
}

int main()
{
    int testCase = getTestCaseNum();
    getMinMax(testCase);
}