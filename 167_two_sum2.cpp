#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> result;
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {};
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15}; // Example input
    int target = 9;
    vector<int> result = twoSum(numbers, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
