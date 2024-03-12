#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n^n) which is exponential and space complexity is o(n^2)
    void solve(int col, int &ans, vector<string> &board, int n, vector<int> &leftRow,
               vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
    {
        if (col == n)
        {
            ans += 1;
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (lowerDiagonal[row + col] == 0 && leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, ans, board, n, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    int totalNQueens(int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> board(n, string(n, '.'));
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> leftRow(n, 0);
        int ans = 0;
        solve(0, ans, board, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

int main()
{
    return 0;
}