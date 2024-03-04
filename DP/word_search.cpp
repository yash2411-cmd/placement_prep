#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n*m*K) where k is the number of solve function calls, and space complexity is O(K) where k is recursive call stack
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int index)
    {

        // checking if the index of word has reached the last character  or not if it is then return true
        if (index == word.size())
        {
            return true;
        }

        int n = board.size();
        int m = board[0].size();
        // checking the  boundaries and validity of the current cell
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index])
        {
            return false;
        }
        // marking the cells for backtracking
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = solve(board, word, i + 1, j, index + 1) || solve(board, word, i - 1, j, index + 1) || solve(board, word, i, j + 1, index + 1) ||
                     solve(board, word, i, j - 1, index + 1);

        // backtracking
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (solve(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}