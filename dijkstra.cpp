#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<pair<int, int>>> g(N);
vector<bool> visited(N, false);
vector<int> dist(N, INT_MAX);

void dijkstra(int source)
{
    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source] = 0;

    while (!s.empty())
    {
        auto node = *s.begin();
        int nodeVal = node.second;
        s.erase(s.begin());

        if (visited[nodeVal])
            continue;
        visited[nodeVal] = true;

        for (auto child : g[nodeVal])
        {
            int wt = child.second;
            int childVal = child.first;

            if (dist[nodeVal] + wt < dist[childVal])
            {
                dist[childVal] = dist[nodeVal] + wt;
                s.insert({dist[childVal], childVal});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    int source, dest;
    cin >> source >> dest;

    dijkstra(source);

    cout << dist[dest] << "\n";

    return 0;
}