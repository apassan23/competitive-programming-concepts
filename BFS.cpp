#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<int>> g(N);
vector<bool> visited(N);
vector<int> level(N);

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int child : g[currentNode])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[currentNode] + 1;
            }
        }
    }
    cout << "\n";
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

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << level[i] << "\n";
    }

    return 0;
}