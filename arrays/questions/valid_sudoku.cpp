#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {
        unordered_set<char> seen;

        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] != '.' && !seen.insert(board[row][i]).second)
            {
                return false;
            }
        }

        seen.clear();

        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.' && !seen.insert(board[i][col]).second)
            {
                return false;
            }
        }

        seen.clear();

        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] != '.' && !seen.insert(board[i][j]).second)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    if (!isSafe(row, col, board, board[row][col]))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}