#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                result = mid;
                right = mid - 1; // keep searching on the left
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }

    int findLast(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                result = mid;
                left = mid + 1; // keep searching on the right
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> res = sol.searchRange(nums, target);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;

    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int left = 0, right = nums.size() - 1;

//         while (left <= right)
//         {
//             // Move left pointer to the right if not at target
//             if (nums[left] != target)
//                 left++;
//             // Move right pointer to the left if not at target
//             if (nums[right] != target)
//                 right--;

//             // When both pointers are at target
//             if (nums[left] == target && nums[right] == target)
//                 return {left, right};
//         }

//         return {-1, -1}; // target not found
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> nums = {5, 7, 7, 8, 8, 10};
//     int target = 8;

//     vector<int> res = sol.searchRange(nums, target);
//     cout << "[" << res[0] << ", " << res[1] << "]" << endl;

//     return 0;
// }
