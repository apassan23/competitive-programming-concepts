#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> movements = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;

bool isValid(int &x, int &y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(vector<vector<int>> &mat, vector<vector<int>> &level, vector<vector<bool>> &visited)
{
    int maxVal = 0;

    for (auto &vec : mat)
    {
        for (auto &e : vec)
        {
            maxVal = max(maxVal, e);
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == maxVal)
            {
                q.push({i, j});
                level[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto point = q.front();
        q.pop();

        for (auto &movement : movements)
        {
            int newX = point.first + movement.first;
            int newY = point.second + movement.second;

            if (!isValid(newX, newY))
                continue;
            if (visited[newX][newY])
                continue;

            q.push({newX, newY});
            level[newX][newY] = level[point.first][point.second] + 1;
            visited[newX][newY] = true;
            ans = max(ans, level[newX][newY]);
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<vector<int>> val(n, vector<int>(m)), level(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }

        cout << bfs(val, level, visited) << "\n";
    }

    return 0;
}