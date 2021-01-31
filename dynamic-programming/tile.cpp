#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int len;
int cases = 0;
vector<string> tiles;
string tile;

void getTileCases(int count)
{
    if (count > len)
    {
        return;
    }
    if (count == len)
    {
        cases++;
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        if (i == 0)
        {
            tile.append("00");

            getTileCases(count + 2);
            tile = tile.substr(0, tile.length() - 2);
        }
        else
        {
            tile.append("1");

            getTileCases(count + 1);
            tile = tile.substr(0, tile.length() - 1);
        }
    }
}

int main()
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        tiles.push_back("1");
    }
    for (int i = 0; i < len / 2; i++)
    {
        tiles.push_back("00");
    }
    // for (int j = 0; j < tiles.size(); j++)
    // {
    //     cout << tiles[j] << " ";
    // }
    // cout << endl;

    getTileCases(0);
    // cout << cases << endl;
    cout << cases % 15746 << '\n';
}