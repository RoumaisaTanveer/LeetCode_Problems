#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>
using namespace std;
void countSort(vector<pair<int, string>> &arr)
{
    int n = arr.size();
    vector<vector<string>> countarray(100);
    for (size_t i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            countarray[arr[i].first].push_back("-");
        }
        else
        {
            countarray[arr[i].first].push_back(arr[i].second);
        }
    }
    for (const auto &group : countarray)
    {
        for (const auto &str : group)
        {
            cout << str << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    countSort(arr);
    return 0;
}