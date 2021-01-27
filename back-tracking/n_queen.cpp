#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
int result;
// 퀸이 위치해있는 배열
vector<pair<int, int>> queenLocation;

// 퀸을 해당 위치에 놓을 수 있는지 true/false 값 반환 
bool putQueen(const int &r, const int &c)
{
    for (pair<int, int> p : queenLocation)
    {
        int row = p.first;
        int col = p.second;
        if (r == row || c == col || abs(r - row) == abs(c - col))
            return false;
    }
    return true;
}

// back-tracking
void dfs(const int &r)
{
    if (n == r)
    {
        result++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (putQueen(r + 1, i))
        {
            queenLocation.push_back(make_pair(r + 1, i));
            dfs(r + 1);
            queenLocation.erase(queenLocation.end() - 1);
        }
    }
}

int main(void)
{
    cin >> n;
    dfs(0);
    cout << result << '\n';
}