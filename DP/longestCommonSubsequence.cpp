#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

// O(N^2)
int lcs(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // remove 1 char from s1
    int ans = lcs(i - 1, j, s1, s2);
    // remove 1 char from s2
    ans = max(ans, lcs(i, j - 1, s1, s2));
    // remove 1 char from s1 and s2
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
    return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
}

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    cout << longestCommonSubsequence(text1, text2);
    return 0;
}