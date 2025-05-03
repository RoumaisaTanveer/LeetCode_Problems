#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// int stringConstruction(string str){
//     bool char_present[26]={false};
//     int unique_count=0;

//     for(int i=0;i<str.length();i++){
//         int index = str[i]-'a';
//         if(!char_present[index]){
//             char_present[index]=true;
//             unique_count++;
//         }
//     }
//     return unique_count;
// }

int stringConstruction(string s){
    unordered_set<char>unique_chars(s.begin(),s.end());
    return unique_chars.size();
}


int main() {

    int n;
    cin>>n;
    cin.ignore();
   while(n--){
    string s;
    getline(cin, s);
    cout<<stringConstruction(s)<<endl;
}
    return 0;
}