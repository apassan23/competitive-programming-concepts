#include <bits/stdc++.h>
using namespace std;

// func(index, value) :-> minimum weight required to obtain value
vector<vector<long long>> dp;
vector<int> wt, val;

// Complexity: O(N*V)
long long func(int ind, int value_left)
{
    if (value_left == 0)
        return 0;
    if (ind < 0)
        return 1e15;

    if (dp[ind][value_left] != -1)
        return dp[ind][value_left];

    // Dont choose
    long long ans = func(ind - 1, value_left);

    // Choose
    if (value_left >= val[ind])
        ans = min(ans, func(ind - 1, value_left - val[ind]) + wt[ind]);

    return dp[ind][value_left] = ans;
}

int main()
{

    int items, _wt;
    cin >> items >> _wt;
    dp = vector<vector<long long>>(1e2 + 10, vector<long long>(1e5 + 10, -1));
    wt = val = vector<int>(1e2 + 10);

    for (int i = 0; i < items; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for (int i = 1e5; i >= 0; i--)
    {
        if (func(items - 1, i) <= _wt)
        {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}