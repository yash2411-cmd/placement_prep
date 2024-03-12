#include <bits/stdc++.h>
using namespace std;

// optimized
class Solution
{
public:
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &leftRow,
               vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
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

    vector<vector<string>> solveNQueens(int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> board(n, string(n, '.'));
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> leftRow(n, 0);

        vector<vector<string>> ans;
        solve(0, ans, board, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

// normal approach with exponential time complexity and space complexity is O(N^2 + k)
class Solution
{
public:
    void addanswer(int n, vector<vector<char>> &board, vector<vector<string>> &ans)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string row = "";
            for (int j = 0; j < n; j++)
            {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {
        // Check row on the left side
        for (int i = 0; i < col; i++)
        {
            if (board[row][i] == 'Q')
            {
                return false;
            }
        }

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<char>> &board, int n)
    {
        if (col == n)
        {
            addanswer(n, board, ans);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};

int main()
{
    return 0;
}