#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getPlusTable()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;

        while (true)
        {
            if ((a >= 0) && (b < 10))
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if(a == 0 && b == 0){
            break;
        }else{
            cout << a + b << endl;
        }
    }
}

int main()
{
    getPlusTable();
}
