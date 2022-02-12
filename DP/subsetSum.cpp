#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool func(int i, int sum, vector<int> &nums)
{
    if (sum == 0)
        return true;
    if (i < 0)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];
    // not consider ith index
    bool isPossible = func(i - 1, sum, nums);
    // consider ith index
    if (sum >= nums[i])
        isPossible |= func(i - 1, sum - nums[i], nums);

    return dp[i][sum] = isPossible;
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1)
        return false;

    sum = sum / 2;
    return func(nums.size() - 1, sum, nums);
}

int main()
{
    dp = vector<vector<int>>(205, vector<int>(2e4 + 10, -1));
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int &e : nums)
        cin >> e;

    cout << (canPartition(nums) ? "Yes" : "No");

    return 0;
}