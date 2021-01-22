#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int blackJack(int n, int m)
{
    int res;
    int minus;
    vector<int> cards;
    vector<int> cards_sum;
    vector<int> af_cards_sum;
    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    for (int i = 0; i <= cards.size() - 3; i++)
    {
        for (int j = i + 1; j <= cards.size() - 2; j++)
        {
            for (int l = j + 1; l <= cards.size() - 1; l++)
            {
                cards_sum.push_back(cards[i] + cards[j] + cards[l]);
            }
        }
    }

    for (int i = 0; i < cards_sum.size(); i++)
    {
        cards_sum[i] = m - cards_sum[i];
    }

    sort(cards_sum.begin(), cards_sum.end());

    // // print for check
    // for (int i = 0; i < cards_sum.size(); i++)
    // {
    //     cout << cards_sum[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < cards_sum.size(); i++)
    {
        if (cards_sum[i] < 0)
        {
            continue;
        }
        else
        {
            return m - cards_sum[i];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << blackJack(n, m) << '\n';
}