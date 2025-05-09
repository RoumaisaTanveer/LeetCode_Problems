#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <string>
using namespace std;

#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> countS, countT;

        for (char c : s)
        {
            countS[c]++;
        }

   
        for (char c : t)
        {
            countT[c]++;
        }

        
        return countS == countT;
    }
};

int main()
{
    string s = "ali";
    string t = "ail";

    Solution solution;
    bool result = solution.isAnagram(s, t);

    // Output the result
    if (result)
    {
        cout << "The strings are anagrams!" << endl;
    }
    else
    {
        cout << "The strings are NOT anagrams!" << endl;
    }

    return 0;
}