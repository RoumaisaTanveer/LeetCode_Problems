#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;
        grid[r][c] = '0'; /// visited
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {

        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};
int main()
{
    return 0;
}