#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    //     vector<int> merged(nums1.begin(), nums1.end());
    //     merged.insert(merged.end(), nums2.begin(), nums2.end());

    //     sort(merged.begin(), merged.end());

    //     int n = merged.size();
    //     if (n % 2 == 1)
    //         return merged[n / 2]; // Odd size
    //     else
    //         return (merged[n / 2 - 1] + merged[n / 2]) / 2.0; // Even size
    // }

    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Make sure A is the smaller array
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);

        int m = A.size();
        int n = B.size();
        int low = 0, high = m;

        while (low <= high) {
            int partitionA = (low + high) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : A[partitionA];

            int maxLeftB = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : B[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Even total length
                if ((m + n) % 2 == 0)
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                // Odd total length
                else
                    return max(maxLeftA, maxLeftB);
            } else if (maxLeftA > minRightB) {
                high = partitionA - 1;
            } else {
                low = partitionA + 1;
            }
        }

        return 0.0; // Should never reach here
    }
};


int main()
{
    return 0;
}