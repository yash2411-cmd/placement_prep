#include <bits/stdc++.h>
using namespace std;
class NumMatrix
{
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix.resize(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefix[i][j] = matrix[i][j];
                if (j > 0)
                {
                    prefix[i][j] += prefix[i][j - 1];
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < m; i++)
            {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (prefix.empty())
        {
            return 0;
        }

        int sum = prefix[row2][col2];
        if (row1 > 0)
        {
            sum -= prefix[row1 - 1][col2];
        }
        if (col1 > 0)
        {
            sum -= prefix[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0)
        {
            sum += prefix[row1 - 1][col1 - 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    return 0;
}