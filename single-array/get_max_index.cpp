#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void getMaxIndex()
{
    vector<int> array;
    for (int i = 0; i < 9; i++)
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a >= 1 && a < 100)
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
    
    vector<int> arrayForIndex = array;

    sort(array.begin(), array.end());
    int index = 0;
    for(int i = 1; i <= array.size(); i++){
        if(array[array.size()-1] == arrayForIndex[i-1]){
            index = i;
        }
    }

    cout << array[array.size()-1] << endl;
    cout << index << endl;
}

int main()
{
    getMaxIndex();
}