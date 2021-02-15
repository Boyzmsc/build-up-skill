#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    stack<int> aBook;

    while (t--)
    {
        int money;
        cin >> money;
        if (money == 0)
        {
            aBook.pop();
        }
        else
        {
            aBook.push(money);
        }
    }

    int totalPrice = 0;
    int size = aBook.size();
    for (int i = 0; i < size; i++)
    {
        totalPrice += aBook.top();
        aBook.pop();
    }
    cout << totalPrice << '\n';
}