 #include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
       bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream stream(s);
        string word;
        int i = 0;
    
        while (stream >> word) {
            if (i >= pattern.size()) return false;
    
            char p = pattern[i];
    
            if (charToWord.count(p)) {
                if (charToWord[p] != word) return false;
            } else {
                if (wordToChar.count(word)) return false;
    
                charToWord[p] = word;
                wordToChar[word] = p;
            }
            i++;
        }
    
        return i == pattern.size();
    }
    
    };