#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
double getMedian(vector<int> &count, int d)
{
    int sum = 0;
    int median1 = -1;
    int median2 = -1;
    int middle = d / 2; // middle of trailing days to check median condiiton
    for (int i = 0; i < count.size(); i++)
    {
        sum += count[i];
        if (median1 == -1 && sum > middle - (d % 2 == 0 ? 1 : 0))
        {
            /// first half elemets of trailing dayss
            median1 = i;
        }
        if (median2 == -1 && sum >= (middle + 1))
        { // check if odd d
            median2 = i;
            break;
        }
    }
    return (median1 + median2) / 2.0;
}

int getNotifications(vector<int> expenditures, int d)
{
    vector<int> count(201, 0); // 0-200
    int notifications = 0;

    for (int i = 0; i < d; i++)
    {
        count[expenditures[i]]++;
    }
    for (int i = d; i < expenditures.size(); i++)
    {
        long double median = getMedian(count, d);
        if (expenditures[i] >= 2 * median) // as position one ele
        {
            notifications++;
        }

        count[expenditures[i]]++;     // after d days next elwnt is added and the oldest is removed decrsing its frequecy in array
        count[expenditures[i - d]]--; // remove oldest element
    }
    return notifications;
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for (int i = 0; i < n; i++)
    {
        cin >> expenditure[i];
    }

    cout << getNotifications(expenditure, d) << endl;
    return 0;
}