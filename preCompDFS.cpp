#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> subtree_sum(N);
vector<int> even_ct(N);

vector<vector<int>> g(N);

void dfs(int vertex, int parent = 0)
{
    if (!(vertex & 1))
        even_ct[vertex]++;
    subtree_sum[vertex] += vertex;
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];
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

    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << subtree_sum[i] << " " << even_ct[i] << "\n";
    }

    return 0;
}