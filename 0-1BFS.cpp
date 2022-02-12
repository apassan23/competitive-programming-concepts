#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<vector<pair<int, int>>> g(N);
vector<int> level(N, INF);

int bfs(int n)
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    // find(level.begin(), level.end(), 9);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop_front();

        for (auto child : g[currentNode])
        {
            int childVal = child.first;
            int wt = child.second;

            if (level[currentNode] + wt < level[childVal])
            {
                level[childVal] = level[currentNode] + wt;

                if (wt == 1)
                {
                    q.push_back(childVal);
                }
                else
                {
                    q.push_front(childVal);
                }
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    cout << bfs(n) << "\n";

    return 0;
}