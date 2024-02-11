#include <bits/stdc++.h>
using namespace std;
class Solution

// given a matrix create a same matrix with same elements and then modify the ans matrix element to the max element of that coloumn value
// where matrix has -1

{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(row, vector<int>(col));
        vector<int> colmax(col);
        for (int j = 0; j < col; j++)
        {
            int maxval = matrix[0][j];
            for (int i = 1; i < row; i++)
            {
                maxval = max(maxval, matrix[i][j]);
            }
            colmax[j] = maxval;
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == -1)
                {
                    ans[i][j] = colmax[j];
                }
                else
                {
                    ans[i][j] = matrix[i][j];
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