// // // class Solution
// // // {
// // // public:
// // //     int removeElement(vector<int> &nums, int val)
// // //     {
// // //         int k = 0; // non val
// // //         for (int i = 0; i < nums.size(); i++)
// // //         {
// // //             if (nums[i] != val)
// // //             {
// // //                 nums[k] = nums[i];
// // //                 k++;
// // //             }
// // //         }
// // //         return k;
// // //     }
// // // }

// // // int
// // // removeELement(vector<int> &nums, int val)
// // // {
// // //     int i = 0;
// // //     int n = nums.size();
// // //     while (i < n)
// // //     {
// // //         if (nums[i] == val)
// // //         {
// // //             nums[i] = nums[n - 1];
// // //             n--;
// // //         }
// // //         else
// // //         {
// // //             i++;
// // //         }
// // //     }
// // //     return n;
// // // }

// // // int removeDuplicates(vector<int> &nums)
// // // {
// // //     int k = 0;
// // //     for (int i = 1; i < nums.size(); i++)
// // //     {
// // //         if (nums[i] != nums[i - 1])
// // //         {
// // //             k++;
// // //         }
// // //     }
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // #include <vector>
// // #include <unordered_map>
// // using namespace std;

// // int majorityElement(vector<int>& nums) {
// //     unordered_map<int, int> count;
// //     int n = nums.size();

// //     for (int num : nums) {
// //         count[num]++;
// //         if (count[num] > n / 2) {
// //             return num;
// //         }
// //     }

// //     // This line should never be reached if input always contains a majority
// //     return -1;
// // }
// // int majorityElement(vector<int>& nums) {
// //     int count = 0;
// //     int candidate = 0;

// //     for (int num : nums) {
// //         if (count == 0) {
// //             candidate = num;
// //         }
// //         count += (num == candidate) ? 1 : -1;
// //     }

// //     return candidate;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// // int maxProfit(vector<int> &prices)
// // {
// //     if (prices.size() < 2)
// //         return 0;

// //     int minPrice = prices[0];
// //     int maxProfit = 0;

// //     for (int i = 1; i < prices.size(); ++i)
// //     {
// //         maxProfit = max(maxProfit, prices[i] - minPrice);
// //         minPrice = min(minPrice, prices[i]);
// //     }

// //     return maxProfit;
// // }

// #include <iostream>
// #include <vector>
// using namespace std;

// // bool canJump(vector<int> &nums)
// // {
// //     int n = nums.size();
// //     int maxReach = 0;
// //     for (int i = 0; i < nums.size(); i++)
// //     {
// //         if (i > maxReach)
// //         {
// //             return false;
// //         }
// //         maxReach = max(maxReach, i + nums[i]);
// //     }

// //     return true;
// // }
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// vector<int> findJumpPath(const vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> prev(n, -1); // to reconstruct the path
//     vector<bool> visited(n, false);

//     queue<int> q;
//     q.push(0);
//     visited[0] = true;

//     while (!q.empty())
//     {
//         int i = q.front();
//         q.pop();

//         for (int j = 1; j <= nums[i] && i + j < n; ++j)
//         {
//             int next = i + j;
//             if (!visited[next])
//             {
//                 visited[next] = true;
//                 prev[next] = i;
//                 q.push(next);
//                 if (next == n - 1)
//                     break; // stop when we reach the end
//             }
//         }
//     }

//     // Reconstruct the path
//     vector<int> path;
//     for (int at = n - 1; at != -1; at = prev[at])
//     {
//         path.push_back(at);
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }

// int main()
// {
//     vector<int> nums = {2, 3, 1, 1, 4};
//     vector<int> path = findJumpPath(nums);

//     cout << "Jump Path:" << endl;
//     for (size_t i = 0; i < path.size() - 1; ++i)
//     {
//         cout << "Jump " << i + 1 << ": " << path[i] << " -> " << path[i + 1] << endl;
//     }

//     cout << "Minimum number of jumps: " << path.size() - 1 << endl;
//     return 0;
// }

// // int main()
// // {
// //     vector<int> nums = {2, 3, 1, 1, 4};
// //     int result = jump(nums);
// //     cout << "Minimum number of jumps: " << result << endl;
// //     return 0;
// // }

// // int main()
// // {
// //     vector<int> nums;
// //     int input[] = {3, 2, 1, 0, 4}; // This is a typical Jump Game input
// //     int size = sizeof(input) / sizeof(input[0]);

// //     for (int i = 0; i < size; ++i)
// //     {
// //         nums.push_back(input[i]);
// //     }

// //     bool canReach = jump(nums);
// //     cout << (canReach ? "true" : "false") << endl;

// //     return 0;
// //
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i)
    {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> answer = productExceptSelf(nums);

    cout << "Output: ";
    for (int num : answer)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
