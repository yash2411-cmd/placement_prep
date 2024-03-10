#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int n, int c, int m, vector<vector<char>> &board)
    {
        if (r < 0 || c < 0 || c >= m || r >= n || board[r][c] != 'O')
        {
            return;
        }
        board[r][c] = 'T';
        dfs(r - 1, n, c, m, board);
        dfs(r, n, c - 1, m, board);
        dfs(r + 1, n, c, m, board);
        dfs(r, n, c + 1, m, board);
    }
    void solve(vector<vector<char>> &board)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(i, n, 0, m, board);
            }
            if (board[i][m - 1] == 'O')
            {
                dfs(i, n, m - 1, m, board);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                dfs(0, n, j, m, board);
            }
            if (board[n - 1][j] == 'O')
            {
                dfs(n - 1, n, j, m, board);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main()
{
    return 0;
}