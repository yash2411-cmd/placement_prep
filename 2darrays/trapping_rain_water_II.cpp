#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity of this solution is O(r*c log(r*c));
    // space complexity is O(r*c);
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int r = heightMap.size();
        int c = heightMap[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
                {
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        int Max_water = 0;
        int Minheight = 0;
        while (!pq.empty())
        {
            int curr_height = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            Minheight = max(curr_height, Minheight);
            pq.pop();
            int dr[4] = {0, 0, -1, 1};
            int dc[4] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && vis[nr][nc] == false)
                {
                    pq.push({heightMap[nr][nc], {nr, nc}});
                    vis[nr][nc] = true;
                    if (heightMap[nr][nc] < Minheight)
                    {
                        Max_water += Minheight - heightMap[nr][nc];
                    }
                }
            }
        }
        return Max_water;
    }
};

int main()
{
    return 0;
}