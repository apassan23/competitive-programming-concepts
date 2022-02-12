#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<int> depth(N);

void dfs(int vertex, int parent = -1)
{
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // brute force
    // int overall_max_depth = -1;
    // for (int i = 1; i <= n; i++)
    // {
    //     dfs(i);
    //     int max_depth = -1;
    //     for (int j = 1; j <= n; j++)
    //     {
    //         max_depth = max(max_depth, depth[j]);
    //         depth[j] = 0;
    //     }
    //     overall_max_depth = max(overall_max_depth, max_depth);
    // }

    // cout << overall_max_depth << "\n";

    dfs(1);
    // find the max depth node from root
    auto it = max_element(depth.begin() + 1, depth.begin() + n + 1);
    fill(depth.begin(), depth.begin() + n + 1, 0);

    dfs(distance(depth.begin(), it));
    cout << *max_element(depth.begin() + 1, depth.begin() + n + 1) << "\n";

    return 0;
}