#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

void insertionSort1(int n, vector<int> &arr)
{
    // int value = arr[n - 1]; // select value at index starting
    // int i = n - 2;
    // while (i >= 0 && arr[i] > value)
    // { // leftward shifting until found righ postion

    //     arr[i + 1] = arr[i];
    //     i--;
    //     for (int num : arr)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
    // arr[i + 1] = value;
    // for (int num : arr)
    // {
    //     cout << num << " ";
    // }
    // cout << endl;
    int shift = 0;
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
            shift++;
        }

        arr[j + 1] = value;
        // for (int num : arr)
        // {
        //     cout << num << " ";
        // }
        // cout << endl;

        // if (j + 1 != i)
        // {
        //     for (int num : arr)
        //     {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        // the comments are for chnaging the ouput format
    }
    cout << shift << endl;
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

    insertionSort1(n, arr);
    return 0;
}