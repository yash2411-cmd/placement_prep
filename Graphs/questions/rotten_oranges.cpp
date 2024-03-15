#include <bits/stdc++.h>
using namespace std;
// using bfs
class Solution
{
public:
    // time and space complexity is O(n*m)
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int fresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto pp = q.front();
            q.pop();
            int r = pp.first.first;
            int c = pp.first.second;
            int t = pp.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + row[i];
                int nc = c + col[i];
                // int nr = r+row[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == false)
                {
                    vis[nr][nc] = true;
                    q.push({{nr, nc}, t + 1});
                    fresh--;
                }
            }
            ans = t;
        }

        if (fresh > 0)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

class Solutionone
{
public:
    // time and space complexity is O(n*m) and O(1)
    int orangesRotting(vector<vector<int>> &grid)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int fresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int si = q.size();
            // q.pop();
            bool rotten = false;
            for (int j = 0; j < si; j++)
            {
                auto pp = q.front();
                q.pop();
                int r = pp.first;
                int c = pp.second;
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + row[i];
                    int nc = c + col[i];
                    // int nr = r+row[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2; // setting the next grid rotten
                        q.push({nr, nc});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten)
                ans++;
        }

        if (fresh > 0)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

int main()
{
    return 0;
}