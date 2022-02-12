#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int lis(int i, vector<int> &a)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, lis(j, a) + 1);
        }
    }

    return dp[i] = ans;
}

int main()
{
    vector<int> a;

    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }
    int ans = 1;

    dp = vector<int>(a.size(), -1);

    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans, lis(i, a));
    }

    cout << ans;
}