#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

// 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
// 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
// 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
// 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
// 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
int main()
{
    while (true)
    {
        string s;
        getline(cin, s);

        stack<char> stack;
        bool check = true;

        if (s[0] == '.')
        {
            break;
        }

        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '(' || s[i] == '[')
            {
                stack.push(s[i]);
            }
            else if ((s[i] == ')' || s[i] == ']') && stack.size() == 0)
            {
                check = false;
                break;
            }
            else if (s[i] == ')' && stack.top() == '[')
            {
                check = false;
                break;
            }
            else if (s[i] == ']' && stack.top() == '(')
            {
                check = false;
                break;
            }
            else if (s[i] == ')' && stack.top() == '(')
            {
                stack.pop();
            }
            else if (s[i] == ']' && stack.top() == '[')
            {
                stack.pop();
            }
            i++;
        }

        if (!check)
        {
            cout << "no" << '\n';
            continue;
        }

        if (stack.size() == 0)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}