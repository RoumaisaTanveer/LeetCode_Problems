#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
bool compare(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

vector<string> bigSorting(vector<string> unsorted)
{
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}
int main()
{

    int n;
    cin >> n;
    vector<string> unsorted(n);

    for (int i = 0; i < n; i++)
    {
        cin >> unsorted[i];
    }

    vector<string> sortedNumbers = bigSorting(unsorted);

    for (const string &num : sortedNumbers)
    {
        cout << num << "\n";
    }
    vector<string> array(n);

    return 0;
}
