#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {

        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
            if (board[i][col] == val)
            {
                return false;
            }

            // 3x3 matrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                if (board[row][col] == '.')
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (isSafe(row, col, board, '0' + val))
                        {
                            board[row][col] = val + '0';

                            bool solution = solve(board);
                            if (solution)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        solve(board);
    }
};

int main()
{
    return 0;
}