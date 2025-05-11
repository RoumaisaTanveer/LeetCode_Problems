 #include <bits/stdc++.h>
using namespace std;


 vector<vector<string>> groupAnagrams(vector<string>& strs){
     unordered_map<string, vector<string>> res;
     for(const auto&s:strs){
         string key = s;
         sort(key.begin(), key.end());
         res[key].push_back(s);  
     }

     vector < vector<string>> result;
     for(auto&pair : res){
         result.push_back(pair.second);
     }
 }
int main() {
    return 0;
}