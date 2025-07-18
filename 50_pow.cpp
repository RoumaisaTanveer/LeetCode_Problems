#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    // Convert n to long to handle INT_MIN
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}
int main()
{
    return 0;
}