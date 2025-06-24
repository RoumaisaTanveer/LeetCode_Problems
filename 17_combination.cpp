 #include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
class Solution {
void backtrack(int index, const string& digits, const vector<string>& phoneMap,string& current, vector<string>& result){
    if(index==digits.size()){
        result.push_back(current);
        return;
    }
    string letters=phoneMap[digits[index]-'0'];
    for(char letter:letters){
        current.push_back(letter);
        backtrack(index + 1, digits, phoneMap, current, result);
        current.pop_back();
    }
}
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>result;
        string current;
        vector<string>phoneMap={
             "",     "",     "abc", "def", "ghi", "jkl",
            "mno",  "pqrs", "tuv", "wxyz"
        };

        backtrack(0,digits,phoneMap,current,result);
        return result;
    }
};
