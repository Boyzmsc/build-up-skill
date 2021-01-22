#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void chessBoard(int n, int m)
{
    int N = n;
    vector<string> board;
    vector<int> counts;
    while (N--)
    {
        string line;
        cin >> line;
        board.push_back(line);
    }
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            // case -> 'W'
            int count_first = 0;
            for (int x = i; x <= i + 7; x++)
            {
                for (int y = j; y <= j + 7; y++)
                {
                    if (x == i && y == j)
                    {
                        if(board[x][y] == 'W'){
                            continue;
                        }else{
                            count_first++;
                        }
                    }
                    else if ((x - i) % 2 == 1 && (y - j) % 2 == 0)
                    {
                        if (board[x][y] == 'W')
                        {
                            count_first++;
                        }
                    }
                    else if ((x - i) % 2 == 0 && (y - j) % 2 == 0)
                    {
                        if (board[x][y] == 'B')
                        {
                            count_first++;
                        }
                    }
                    else if ((x - i) % 2 == 1 && (y - j) % 2 == 1)
                    {
                        if (board[x][y] == 'B')
                        {
                            count_first++;
                        }
                    }
                    else if ((x - i) % 2 == 0 && (y - j) % 2 == 1)
                    {
                        if (board[x][y] == 'W')
                        {
                            count_first++;
                        }
                    }
                }
            }
            // case -> 'B'
            int count_second = 0;
            for (int x = i; x <= i + 7; x++)
            {
                for (int y = j; y <= j + 7; y++)
                {
                    if (x == i && y == j)
                    {
                        if(board[x][y] == 'B'){
                            continue;
                        }else{
                            count_second++;
                        }
                    }
                    else if ((x - i) % 2 == 1 && (y - j) % 2 == 0)
                    {
                        if (board[x][y] == 'B')
                        {
                            count_second++;
                        }
                    }
                    else if ((x - i) % 2 == 0 && (y - j) % 2 == 0)
                    {
                        if (board[x][y] == 'W')
                        {
                            count_second++;
                        }
                    }
                    else if ((x - i) % 2 == 1 && (y - j) % 2 == 1)
                    {
                        if (board[x][y] == 'W')
                        {
                            count_second++;
                        }
                    }
                    else if ((x - i) % 2 == 0 && (y - j) % 2 == 1)
                    {
                        if (board[x][y] == 'B')
                        {
                            count_second++;
                        }
                    }
                }
            }
            counts.push_back(min(count_first, count_second));
            // cout << count_first << " " << count_second << endl;
        }
    }
    sort(counts.begin(), counts.end());
    cout << counts[0] << '\n';
}

int main()
{
    int n, m;
    cin >> n >> m;
    chessBoard(n, m);
}