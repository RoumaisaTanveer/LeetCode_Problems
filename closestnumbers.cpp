#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

vector<int> closestnumbers(vector<int> array)
{
    vector<int> result;
    sort(array.begin(), array.end());
    int mindiff = INT_MAX;
    for (int i = 0; i < array.size() - 1; i++)
    {
        int diff = abs(array[i] - array[i + 1]);
        mindiff = min(mindiff, diff);
    }

    for (size_t i = 0; i < array.size() - 1; i++)
    {
        if (abs(array[i] - array[i + 1]) == mindiff)
        {
            result.push_back(array[i]);
            result.push_back(array[i + 1]);
        }
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < array.size(); i++)
    {
        cin >> array[i];
    }
    vector<int> result = closestnumbers(array);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}