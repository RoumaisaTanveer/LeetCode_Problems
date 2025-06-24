#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;

        while (n)
        {
            if (n & 1)
                count++;
            n >>= 1; // right shift  //cpp already binary inside
        }
        return count;
    }
};
int main()
{
    return 0;
}