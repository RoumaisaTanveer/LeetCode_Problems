#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
//what happend is the we calllllily homwork in main that in turn first sort the array given and store it then reverse the array and store it
//we perform countswaps on botyh arrays that uses index mapping the unsorted array is stored with its indexes in index mapping we iterate the array
//and and compare positions with sorted array if tehy dont amtch we use indexmap to find respective element at position andplace at correct index
int countSwaps(vector<int> arr, vector<int> targetArr)
{
    int n = arr.size();

    int swaps = 0;
    unordered_map<int, int> indexMap;

    for (int i = 0; i < n; i++)
    {
        indexMap[arr[i]] = i;
    }

    // cout << "Index mapp" << endl;
    // for (auto it : indexMap)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    // cout << "Using Target Array: ";
    // for (int num : targetArr)
    //     cout << num << " ";
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != targetArr[i])
        {
            swaps++;
            int correctIndex = indexMap[targetArr[i]];
            swap(arr[i], arr[correctIndex]);
            indexMap[arr[correctIndex]] = correctIndex;
            indexMap[arr[i]] = i;
        }
    }
    return swaps;
}

int lilysHomework(vector<int> arr)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    vector<int> reverseSortedArr = sortedArr;
    reverse(reverseSortedArr.begin(), reverseSortedArr.end());

    // cout << "Sorted Array: ";
    // for (int num : sortedArr)
    //     cout << num << " ";
    // cout << endl;

    // cout << "Reverse Sorted Array: ";
    // for (int num : reverseSortedArr)
    //     cout << num << " ";
    // cout << endl;

    return min(countSwaps(arr, sortedArr), countSwaps(arr, reverseSortedArr));
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << lilysHomework(arr) << endl;
    return 0;
}