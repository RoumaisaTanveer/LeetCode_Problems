#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

string twoStrings(string s1,string s2){
    unordered_set<char>unique_char1(s1.begin(),s1.end());
    unordered_set<char>unique_char2(s2.begin(),s2.end());
      for(char c:unique_char1){
        if(unique_char2.find(c)!=unique_char2.end()){
            return "YES";
        }
      }
      return "NO";
}
int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << twoStrings(s1, s2) << endl;
    }
    return 0;
}
