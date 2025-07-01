
#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node *tl, Node *tr, Node *bl, Node *br)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = tl;
        topRight = tr;
        bottomLeft = bl;
        bottomRight = br;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        return build(grid, 0, 0, grid.size());
    }

    Node *build(vector<vector<int>> &grid, int r, int c, int size)
    {
        if (isSame(grid, r, c, size))
        {
            return new Node(grid[r][c] == 1, true);
        }

        int half = size / 2;

        Node *tl = build(grid, r, c, half);
        Node *tr = build(grid, r, c + half, half);
        Node *bl = build(grid, r + half, c, half);
        Node *br = build(grid, r + half, c + half, half);

        return new Node(true, false, tl, tr, bl, br);
    }

    bool isSame(vector<vector<int>> &grid, int r, int c, int size)
    {
        int value = grid[r][c];
        for (int i = r; i < r + size; i++)
        {
            for (int j = c; j < c + size; j++)
            {
                if (grid[i][j] != value)
                    return false;
            }
        }
        return true;
    }
};
