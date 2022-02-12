#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<int> visited(N);

bool dfs(int vertex, int parent)
{
    visited[vertex] = true;
    bool isLoopExists = false;
    for (int child : g[vertex])
    {
        if (visited[child] && child == parent)
            continue;
        if (visited[child])
            return true;
        isLoopExists |= dfs(child, vertex);
    }

    return isLoopExists;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool isLoopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        }
    }

    cout << "Cycle " << (isLoopExists ? "exists" : "does not exists") << "\n";

    return 0;
}