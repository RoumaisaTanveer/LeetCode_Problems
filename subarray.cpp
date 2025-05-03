// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5};

//     // int l = 1, r = 3; // Want to extract elements at index 1 to 3 → {2,3,4}
//     // vector<int> sub(arr.begin() + 0, arr.begin() + 3);

//     // for (int x : sub)
//     //     cout << x << " ";  // Output: 2 3 4

//     for (int i = 0; i <= arr.size() - 3;i++){
//         cout << arr[i] << " " << arr[i + 1] << " " << arr[i + 2] << endl;
//     }
//         return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums={7,8,-3};
    int count = 0;
    int n = nums.size();

    for (int i = 0; i <= n - 3; ++i)
    {
        if (nums[i] + nums[i + 2] == (float)nums[i + 1] / 2.0)
        {
            count++;
        }
    }
    cout << count ;

    return 0;
}