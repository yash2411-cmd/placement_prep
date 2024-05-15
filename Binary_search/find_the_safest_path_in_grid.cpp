#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int manhattan(int a, int b, int x, int y)
    {
        return (abs(a - x) + abs(b - y));
    }
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // time complexity is O(n^2 log n ) since we are traversing the whole grid and we are using dijikstra algorithm concept which has complexity of O(n^2 log n).
    // space complexity is O(n^2)
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // int m = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        // vector<vector<int>> dis(n, vector<int>(m, -1)); // distance vector for nearest thief cell
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }

        // bfs
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == -1)
                {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // smallest safest distance
        priority_queue<vector<int>> pq;
        pq.push(vector<int>{grid[0][0], 0, 0});
        grid[0][0] = -1;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if (curr[1] == n - 1 && curr[2] == n - 1)
            {
                return curr[0];
            }

            for (auto &d : dir)
            {
                int nx = d[0] + curr[1];
                int ny = d[1] + curr[2];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != -1)
                {
                    pq.push(vector<int>{min(curr[0], grid[nx][ny]), nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}