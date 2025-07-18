#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midELement = matrix[mid / n][mid % n];

        if (midELement == target)
        {
            return true;
        }
        else if (midELement < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}
int main()
{
    return 0;
}