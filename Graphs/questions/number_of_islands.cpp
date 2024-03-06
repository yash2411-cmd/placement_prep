#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1; // Mark the starting cell as visited
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // Define directions
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            // Check neighboring cells
            for (auto &dir : directions)
            {
                int r = row + dir.first;
                int c = col + dir.second;
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1' && !vis[r][c])
                {
                    vis[r][c] = 1; // Mark the cell as visited
                    q.push({r, c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}