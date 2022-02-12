#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> h(N), dp(N, -1);

int func(int i, int k)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int cost = INT_MAX;

    for (int j = 1; j <= k && i >= j; j++)
    {
        cost = min(cost, func(i - j, k) + abs(h[i] - h[i - j]));
    }

    return dp[i] = cost;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> h[i];

    cout << func(n - 1, k);

    return 0;
}