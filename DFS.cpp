#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<bool> visited(N);

void dfs(int vertex)
{
    cout << "Vertex " << vertex << "\n";
    visited[vertex] = true;
    for (int child : g[vertex])
    {
        cout << "Parent " << vertex << " child " << child << "\n";
        if (visited[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
    return 0;
}