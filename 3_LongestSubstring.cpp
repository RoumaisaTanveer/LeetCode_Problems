 #include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_set<char>charSet;
        int start = 0;
        int maxLen = 0;
        for (int end = 0; end < s.length();end++){
            while(charSet.find(s[end])!=charSet.end()){
                charSet.erase(s[start]); //remove the duplicate element
                start++;//change window size by moviing pointer ahead
            }
            charSet.insert(s[end]);
            maxLen = max(maxLen, end - start + 1);

        }
        return maxLen;
    }
int main() {
    return 0;
}