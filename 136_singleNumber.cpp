#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> wordCount;
        for (int num : nums)
        {
            wordCount[num]++;
        }
        for (auto &[word, count] : wordCount)
        {
            if (count == 1)
            {
                return word;
            }
        }
        return -1;
    }
};