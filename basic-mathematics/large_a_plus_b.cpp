#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void sum(string a, string b)
{
    int sum = 0;
    string result;
    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
            sum += a.back() - '0', a.pop_back();
        if (!b.empty())
            sum += b.back() - '0', b.pop_back();
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;

    // 밑에 부분도 답은 동일하게 나왔지만 성공 처리가 안됬음
    // 따라서 위에 부분으로 다시 도전 후 성공...
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    // string result;
    // if (a.length() > b.length())
    // {
    //     bool carry = false;
    //     for (int i = 0; i < b.length(); i++)
    //     {
    //         if (carry)
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') + 1 >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1 - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1);
    //                 carry = false;
    //             }
    //         }
    //         else
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0'));
    //                 carry = false;
    //             }
    //         }
    //     }
    //     for (int j = b.length(); j < a.length(); j++)
    //     {
    //         if (carry)
    //         {
    //             if (a[j] - '0' + 1 >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[j] - '0') + 1 - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[j] - '0') + 1);
    //                 carry = false;
    //             }
    //         }
    //         else
    //         {
    //             result += to_string((a[j] - '0'));
    //             carry = false;
    //         }
    //     }
    // }
    // else if (a.length() < b.length())
    // {
    //     bool carry = false;
    //     for (int i = 0; i < a.length(); i++)
    //     {
    //         if (carry == true)
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') + 1 >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1 - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1);
    //                 carry = false;
    //             }
    //         }
    //         else
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0'));
    //                 carry = false;
    //             }
    //         }
    //     }
    //     for (int j = a.length(); j < b.length(); j++)
    //     {
    //         if (carry)
    //         {
    //             if (b[j] - '0' + 1 >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((b[j] - '0') + 1 - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((b[j] - '0') + 1);
    //                 carry = false;
    //             }
    //         }
    //         else
    //         {
    //             result += to_string((b[j] - '0'));
    //             carry = false;
    //         }
    //     }
    // }
    // else if (a.length() == b.length())
    // {
    //     bool carry = false;
    //     for (int i = 0; i < a.length(); i++)
    //     {
    //         if (carry)
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') + 1 >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1 - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0') + 1);
    //                 carry = false;
    //             }
    //         }
    //         else
    //         {
    //             if ((a[i] - '0') + (b[i] - '0') >= 10)
    //             {
    //                 carry = true;
    //                 result += to_string((a[i] - '0') + (b[i] - '0') - 10);
    //             }
    //             else
    //             {
    //                 result += to_string((a[i] - '0') + (b[i] - '0'));
    //                 carry = false;
    //             }
    //         }
    //     }
    //     if (carry)
    //     {
    //         result += "1";
    //     }
    // }
    // reverse(result.begin(), result.end());
    // cout << result << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    sum(a, b);
}