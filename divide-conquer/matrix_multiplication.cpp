#include <bits/stdc++.h>

using namespace std;

int row1, col1, row2, col2;
int matrixA[100][100];
int matrixB[100][100];

int multiple(int x, int y)
{
    int rlt = 0;
    for (int i = 0; i < col1; i++)
    {
        rlt += matrixA[x][i] * matrixB[i][y];
    }
    return rlt;
}

int main()
{
    cin >> row1 >> col1;

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    cin >> row2 >> col2;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << multiple(i, j) << " ";
        }
        cout << endl;
    }
}