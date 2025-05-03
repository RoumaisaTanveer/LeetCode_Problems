#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int findMedian(vector<int> &array)
{
    sort(array.begin(), array.end());
    int mid = array.size() / 2;
    return array[mid];
}

int main()
{
    int n;
    cout << "Enter number of elements:  " << flush;
    cin >> n;
    cout << "Enter " << n << " elements: " << endl;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << findMedian(array) << endl;
    return 0;
}