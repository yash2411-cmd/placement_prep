#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    // time complexity is O(x*4) where x is number of nodes
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int incolor)
    {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nr = dr[i] + row;
            int nc = dc[i] + col;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == incolor && ans[nr][nc] != color)
            {
                dfs(nr, nc, ans, image, color, incolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int incolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color, incolor);
        return ans;
    }
};

int main()
{
    return 0;
}