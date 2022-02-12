#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> parent(N), size(N);

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    // path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // union by size
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    for (int i = 1; i <= n; i++)
        make(i);

    sort(edges.begin(), edges.end());

    int total_cost = 0;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // find find(u) == find(v) means that we
        // can reach the parent of u from u and we
        // can reach the same parent with v
        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        cout << u << " " << v << "\n";
    }

    cout << total_cost << "\n";

    return 0;
}