#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> matrix, int target)
    {
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int count = -1;
            int l = 0;
            int r = matrix[0].size() - 1;
            while (l <= r)
            {
                int mid = (l + (r - l) / 2);
                if (matrix[i][mid] <= target)
                {
                    count = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans += (count + 1);
        }
        return ans;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int l = INT_MAX;
        int r = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                l = min(l, matrix[i][j]);
                r = max(r, matrix[i][j]);
            }
        }

        int req = (R * C) / 2;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);

            int count = solve(matrix, mid);
            if (count <= req)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}