 #include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in right half
                low = mid + 1;
            } else {
                // Minimum is in left half including mid
                high = mid;
            }
        }

        // At this point, low == high, pointing to the smallest element
        return nums[low];
    }
};

int main() {
    return 0;
}