#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n*m) and space is O(1)
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxcount = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int currcount = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    currcount++;
                }
            }
            if (currcount > maxcount)
            {
                maxcount = currcount;
                ans = i;
            }
        }

        return ans;
    }
};

// optimized time complexity is O(n+m)
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans = -1;
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            ans = row;
            col--;
        }
        else
        {
            row++;
        }
    }

    return ans;
}

int main()
{
    return 0;
}