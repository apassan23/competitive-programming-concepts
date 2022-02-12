#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int func(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;

    if (dp[amount] != -1)
        return dp[amount];

    int ans = INT_MAX;
    for (int coin : coins)
    {
        if (amount >= coin)
            ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
    }

    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    dp = vector<int>(1e4 + 10, -1);
    int ans = func(amount, coins);

    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11);

    return 0;
}