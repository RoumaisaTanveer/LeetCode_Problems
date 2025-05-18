#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        // Only start if it's the beginning of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int current = num;
            int length = 1;

            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}
