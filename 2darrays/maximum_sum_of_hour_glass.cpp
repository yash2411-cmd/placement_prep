#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n*m) and space is O(1)
    int findMaxSum(int n, int m, vector<vector<int>> mat)
    {
        int ans = -1;
        int dr[6] = {-1, -1, -1, 1, 1, 1};
        int dc[6] = {-1, 0, 1, 1, 0, -1};
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                int sum = mat[i][j];
                for (int k = 0; k < 6; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    sum += mat[nr][nc];
                }
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}