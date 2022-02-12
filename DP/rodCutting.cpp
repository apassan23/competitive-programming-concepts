#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int func(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;

    if (dp[len] != -1)
        return dp[len];

    int ans = 0;
    for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
    {
        if (len >= len_to_cut)
            ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
    }

    return dp[len] = ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    dp = vector<int>(n + 1, -1);
    for (int &price : prices)
        cin >> price;

    cout << func(n, prices);
}