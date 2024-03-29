#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> onerow(n, 0);
        vector<int> onecol(m, 0);
        vector<int> zerorow(n, 0);
        vector<int> zerocol(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    onerow[i]++;
                    onecol[j]++;
                }
                else
                {
                    zerorow[i]++;
                    zerocol[j]++;
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i][j] = onerow[i] + onecol[j] - zerorow[i] - zerocol[j];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}