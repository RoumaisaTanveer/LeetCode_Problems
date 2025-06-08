#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    // Sort intervals based on the starting value
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    // Iterate and merge overlapping intervals
    for (int i = 1; i < intervals.size(); ++i)
    {
        vector<int> &last = merged.back();
        vector<int> &current = intervals[i];

        if (current[0] <= last[1])
        {
            // if start of current is less than last ka first, so merge
            last[1] = max(last[1], current[1]);
        }
        else
        {
            // No overlap, just push
            merged.push_back(current);
        }
    }

    return merged;
}

int main()
{
    return 0;
}