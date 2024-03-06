#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> &mat, int n)
{
    vector<int> temp1(n), temp2(n);
    temp1[n - 1] = mat[n - 1][n - 1];

    // Loop to fill temp1 with maximum values from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        temp1[i] = max(temp1[i + 1], mat[n - 1][i]);
    }

    int ans = INT_MIN;

    // Loop to iterate through matrix rows from bottom to top
    for (int i = n - 2; i >= 0; i--)
    {
        temp2[n - 1] = max(temp1[n - 1], mat[i][n - 1]);

        // Loop to iterate through matrix columns from right to left
        for (int j = n - 2; j >= 0; j--)
        {
            ans = max(ans, temp1[j + 1] - mat[i][j]);
            temp2[j] = max(temp2[j + 1], max(mat[i][j], temp1[j]));
        }
        temp1 = temp2;
    }
    return ans;
}

int main()
{
    return 0;
}