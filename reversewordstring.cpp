#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

string reverseWords(string str){
    stringstream ss(str);
    string word,result;
    while(ss >> word){ //read words from stream word by word
        stack<char>stk;
        for(char c: word){
            stk.push(c);
        }
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        result+=" "; //add space after each word

    }
    if(!result.empty()){
        result.pop_back(); //remove space
    }
    return result;
}
int main() {
     string str;
     cout<<"ENter string: ";
     getline(cin,str);
     string reversedstring = reverseWords(str);
     cout<<"Reversed string: "<<reversedstring<<endl;
    return 0;
}