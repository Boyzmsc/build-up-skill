#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> pos;

// 특정 블록에 num의 숫자가 들어갈 수 있는지 true/false 리턴
bool check(int row, int col, int num)
{
    for (int k = 0; k < 9; k++)
    {
        if (sudoku[row][k] == num || sudoku[k][col] == num)
        {
            return false;
        }
    }

    for (int x = (row / 3) * 3; x < (row / 3) * 3 + 3; x++)
    {
        for (int y = (col / 3) * 3; y < (col / 3) * 3 + 3; y++)
        {
            if (sudoku[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int count)
{
    if (count == pos.size())
    {
        return true;
    }
    int row = pos[count].first;
    int col = pos[count].second;
    for (int k = 1; k <= 9; k++)
    {
        if (check(row, col, k))
        {
            // 해당 블록을 특정 숫자로 채워넣은 다음
            // back-tracking으로 전체 스도쿠를 풀어봄
            // 하지만 올바르지 않은 숫자 넣음으로 동작 오류가 걸리고 false를 리턴하면
            // 다시 돌아와서 해당 블록을 0으로 초기화한 다음
            // 다른 숫자 (이후에 숫자)로 다시 시도해봄!
            sudoku[row][col] = k;
            if (dfs(count + 1))
            {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                pos.push_back({i, j});
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << '\n';
    }
}