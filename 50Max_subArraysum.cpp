 #include <bits/stdc++.h>
using namespace std;
 int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = 0;

        for (int num : nums) {
            current_sum = max(num, current_sum + num);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
int main() {
    return 0;
}



