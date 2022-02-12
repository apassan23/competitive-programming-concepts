#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<int> wt, val;

// Complexity: O(N*W)
long long func(int ind, int wt_left)
{
    if (wt_left == 0)
        return 0;
    if (ind < 0)
        return 0;
    if (dp[ind][wt_left] != -1)
        return dp[ind][wt_left];

    // Dont choose item at ind
    long long ans = func(ind - 1, wt_left);

    // choose item ind
    if (wt_left >= wt[ind])
        ans = max(ans, func(ind - 1, wt_left - wt[ind]) + val[ind]);

    return dp[ind][wt_left] = ans;
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

    cout << func(items - 1, _wt);

    return 0;
}