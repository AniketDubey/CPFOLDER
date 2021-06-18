#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int dp[505 + 1][505 + 1] = {0};
int score[2] = {0};

int solve(vector<int>piles, int start, int endd, int turn)
{
    if(start>endd)
        return 0;
    
    if(dp[start][endd]>0)
        return dp[start][endd];
    
    if(turn)
    {
        turn = !turn;
        int a = solve(piles, start + 1, endd, turn) + piles[start];
        int b = solve(piles, start, endd - 1, turn) + piles[start];

        dp[start][endd] = max(a, b);
        return dp[start][endd];
    }
    else
    {
        turn = !turn;
        int a = solve(piles, start + 1, endd, turn) - piles[endd];
        int b = solve(piles, start, endd - 1, turn) - piles[endd];

        dp[start][endd] = min(a, b);
        return dp[start][endd];
    }

}

int main()
{

    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n;i++)
    {
        cin >> piles[i];
    }

    int prev = 0;

    int start = 0;
    int endd = n - 1;

    solve(piles, start, endd, prev);

    for (int i = 0; i < 5;i++)
    {
        for (int j = 0;j<5;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
