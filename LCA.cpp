#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<int> parent(N), depth(N);

void dfs(int vertex, int par = -1)
{
    parent[vertex] = par;
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

vector<int> path(int x)
{
    vector<int> result;
    while (x != -1)
    {
        result.push_back(x);
        x = parent[x];
    }

    reverse(result.begin(), result.end());

    return result;
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

    int x, y;
    cin >> x >> y;

    dfs(1);

    // approach 1
    vector<int> path_x = path(x), path_y = path(y);
    int m = min(path_x.size(), path_y.size()) - 1;

    while (path_x[m] != path_y[m])
        m--;

    cout << path_x[m] << "\n";

    // approach 2

    // get x and y to the same depth
    while (depth[x] < depth[y])
        y = parent[y];

    while (depth[x] > depth[y])
        x = parent[x];

    while (x != y)
    {
        x = parent[x];
        y = parent[y];
    }

    cout << x << "\n";

    return 0;
}