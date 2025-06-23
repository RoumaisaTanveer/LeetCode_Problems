#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &board, int rows, int cols)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O')
            return;

        board[r][c] = 'T'; // Mark as safe

        dfs(r + 1, c, board, rows, cols);
        dfs(r - 1, c, board, rows, cols);
        dfs(r, c + 1, board, rows, cols);
        dfs(r, c - 1, board, rows, cols);
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        if (rows == 0)
            return;
        int cols = board[0].size();

        // Step 1: DFS from border 'O's
        for (int r = 0; r < rows; r++)
        {
            if (board[r][0] == 'O')
                dfs(r, 0, board, rows, cols);
            if (board[r][cols - 1] == 'O')
                dfs(r, cols - 1, board, rows, cols);
        }
        for (int c = 0; c < cols; c++)
        {
            if (board[0][c] == 'O')
                dfs(0, c, board, rows, cols);
            if (board[rows - 1][c] == 'O')
                dfs(rows - 1, c, board, rows, cols);
        }

        // Step 2: Flip and restore
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == 'T')
                    board[r][c] = 'O';
            }
        }
    }
};

int main()
{
    return 0;
}