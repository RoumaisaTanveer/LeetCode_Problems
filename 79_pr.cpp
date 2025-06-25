#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int i, int j) {
        // 1. Base cases
        if (index == word.size()) return true;  // found entire word
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false; // out of bounds
        if (board[i][j] != word[index]) return false; // char mismatch

        // 2. Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // 3. Explore neighbors
        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);

        // 4. Backtrack (restore state)
        board[i][j] = temp;

        return found;
    }
};
