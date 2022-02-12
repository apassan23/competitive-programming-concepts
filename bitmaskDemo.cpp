#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSubsets(vector<int> &nums)
{
    vector<vector<int>> subsets;
    int subsetCt = (1 << nums.size());

    for (int i = 0; i < subsetCt; i++)
    {
        vector<int> subset;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i & (1 << j))
                subset.push_back(nums[j]);
        }
        subsets.push_back(subset);
    }

    return subsets;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (auto &e : nums)
        cin >> e;
    auto subsets = getSubsets(nums);

    for (auto vec : subsets)
    {
        for (auto e : vec)
            cout << e << " ";
        cout << "\n";
    }
    return 0;
}