#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> pos;

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