#include <bits/stdc++.h>
using namespace std;
#include <vector>

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to 0 based on markers
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out first row if needed
        if (firstRowZero)
        {
            for (int j = 0; j < cols; ++j)
            {
                matrix[0][j] = 0;
            }
        }

        // Zero out first column if needed
        if (firstColZero)
        {
            for (int i = 0; i < rows; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Add an extra newline for better separation
}
int main()
{
    // Example 1: Basic test case
    std::vector<std::vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    std::cout << "Original Matrix 1:" << std::endl;
    printMatrix(matrix1);

    Solution sol1;
    sol1.setZeroes(matrix1);
    std::cout << "Modified Matrix 1:" << std::endl;
    printMatrix(matrix1);

    return 0;
}