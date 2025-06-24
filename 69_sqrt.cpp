#include <bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    
    int left = 1, right = x, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if ((long long)mid * mid <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}



int main()
{
    int n = 8;
    int result = mySqrt(n);
    cout << result << endl;
    return 0;
}