#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int makingAnagrams(string s1,string s2){
 vector<int>freq(26,0);

 for(char c:s1){
    freq[c - 'a']++; //convert charcer to index
 }
 for(char c:s2){
    freq[c-'a']--;
 }
 int deletions=0;
 for(int i=0;i<26;i++){
    deletions+=abs(freq[i]);
 }
 return deletions;
}

// bool checkanagrams(string s1,string s2){
//     if(s1.length()!=s2.length()) return false;

//     vector<int>freq(26,0);

//     for(char c:s1){
//        freq[c - 'a']++; //convert charcer to index
//     }
//     for(char c:s2){
//        freq[c-'a']--;
//     }
//     for(int c:freq){
// if(c!=0) return false;
//     }
// return true;

//}
int main() {
    string s1, s2;
    cin >> s1 >> s2; // Read input strings
    cout << makingAnagrams(s1, s2) << endl;
     // Print minimum deletions needed
    return 0;
}