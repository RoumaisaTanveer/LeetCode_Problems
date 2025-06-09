 #include <bits/stdc++.h>
using namespace std;
 bool isValidSudoku(vector<vector<char>>& board) {
     unordered_set<char> rows[9], cols[9], boxes[9];
     for (int r = 0; r < 9;r++){
         for (int c = 0; c < 9;c++){
             char val = board[r][c];
             if(val=='.')
                 continue;
             int box_index = (r / 3) * 3 + (c / 3);
             if (rows[r].count(val) || cols[c].count(val) || boxes[box_index].count(val)) {
                return false;
                    // If val already exists in row, column, or box, Sudoku is invalid
            }

            // Mark val as seen
            rows[r].insert(val);
            cols[c].insert(val);
            boxes[box_index].insert(val);
     }
    }
    return true;
}

int main() {
    return 0;
}