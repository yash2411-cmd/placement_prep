#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n*m) and space is also O(n*m)
    void dfs(vector<vector<int>> &land, int i, int j, int &hx, int &hy)
    {
        int n = land.size(), m = land[0].size();
        if (i >= 0 && j >= 0 && i < n && j < m && land[i][j] == 1)
        {
            land[i][j] = 0;
            hx = max(hx, i);
            hy = max(hy, j);
            dfs(land, i + 1, j, hx, hy);
            dfs(land, i, j + 1, hx, hy);
            dfs(land, i - 1, j, hx, hy);
            dfs(land, i, j - 1, hx, hy);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (land[i][j] == 1)
                {
                    int lx = i, ly = j, hx = i, hy = j;
                    dfs(land, i, j, hx, hy);
                    ans.push_back({lx, ly, hx, hy});
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}