#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    int trapped_water = 0;
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        trapped_water += max(0, min(left_max[i], right_max[i]) - height[i]);
    }
    return trapped_water;
}

int main()
{
    vector<int> elevationMap = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped rain water: " << trap(elevationMap) << " units" << endl;
    return 0;
}
