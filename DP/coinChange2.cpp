#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int func(int ind, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;

    if (ind < 0)
        return 0;

    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int ans = 0;

    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind])
    {
        ans += func(ind - 1, amount - coin_amount, coins);
    }

    return dp[ind][amount] = ans;
}

int change(int amount, vector<int> &coins)
{
    dp = vector<vector<int>>(3e2 + 10, vector<int>(1e4 + 10, -1));
    return func(coins.size() - 1, amount, coins);
}

int main()
{
    vector<int> coins = {1, 2, 5};

    cout << change(5, coins);
    return 0;
}