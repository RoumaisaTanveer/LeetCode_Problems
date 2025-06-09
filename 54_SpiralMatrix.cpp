 #include <bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    vector<int> result;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int col = left; col <= right; col++) {
            result.push_back(matrix[top][col]);
        }
        top++;  // move boundary inward

        // Traverse from top to bottom
        for (int row = top; row <= bottom; row++) {
            result.push_back(matrix[row][right]);
        }
        right--;  // move boundary inward

        // Check if still valid
        if (top <= bottom) {
            // Traverse from right to left
            for (int col = right; col >= left; col--) {
                result.push_back(matrix[bottom][col]);
            }
            bottom--;  // move boundary inward
        }

        // Check if still valid
        if (left <= right) {
            // Traverse from bottom to top
            for (int row = bottom; row >= top; row--) {
                result.push_back(matrix[row][left]);
            }
            left++;  // move boundary inward
        }
    }

    return result;
}

int main() {
    return 0;
}