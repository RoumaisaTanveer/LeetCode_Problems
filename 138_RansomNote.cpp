#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomNote, string magazine)
{

    unordered_map<char, int> count_ransom;
    unordered_map<char, int> count_magazine;

    for (char c : ransomNote)
    {
        count_ransom[c]++;
    }

    for (char c : magazine)
    {
        count_magazine[c]++;
    }

    for (auto &elem : count_ransom)
    {
        char c = elem.first;
        int count = elem.second;

        if (count_magazine[c] < count)
        {
            return false;
        }
    }
    return true;
}
int main()
{ string ransomNote = "a1";
    string magazine = "ab";

    if (canConstruct(ransomNote, magazine)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
    
}