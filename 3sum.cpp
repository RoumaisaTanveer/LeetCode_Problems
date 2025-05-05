 #include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<int> result;
    int left = 0;
    int target = 0;
    int right = nums.size() - 1;
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
int main() {
    return 0;
}