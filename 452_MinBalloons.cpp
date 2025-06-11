#include <bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
        return 0;
    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         {
             return a[1] < b[1]; /// sort by end points
         });

    int arrow = 1;
    int arrowPos = points[0][1]; // at the end of first balloon
    for (int i = 0; i < points.size(); i++)
    {    
        if(points[i][0]>arrowPos){
            arrow++;
            arrowPos = points[i][1];
        }
        }
        return arrow;
    }
    int main()
    {
        return 0;
    }