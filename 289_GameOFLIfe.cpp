#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        if (n == 0)
            return;

        // Define directions for the 8 neighbors (dr, dc)
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // Mark cells based on the rules
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int liveNeighbors = 0;
                for (const auto &dir : directions)
                {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // Check if neighbor is within bounds
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                    {
                        // A neighbor is considered 'live' if its current state is 1
                        // or if it was previously 1 and is now marked as 3 (live to dead).

                        if (board[nr][nc] == 1 || board[nr][nc] == 3)
                        {
                            liveNeighbors++;
                        }
                    }
                }

                // Apply Game of Life rules
                if (board[r][c] == 1)
                { // Current cell is live
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                    {
                        board[r][c] = 3; // Mark as live to dead
                    }
                    // else: liveNeighbors is 2 or 3, cell remains 1 (live to live)
                }
                else
                { // Current cell is dead (0)
                    if (liveNeighbors == 3)
                    {
                        board[r][c] = 2; // Mark as dead to live
                    }
                }
            }
        }

        // Update the board to final states
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (board[r][c] == 2)
                {
                    board[r][c] = 1; // Was dead, now alive
                }
                else if (board[r][c] == 3)
                {
                    board[r][c] = 0; // Was alive, now dead
                }
            }
        }
    }
};