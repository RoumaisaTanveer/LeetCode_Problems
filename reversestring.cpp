#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Function to reverse a vector of strings
vector<string> reversestring(vector<string> s) {
    int start = 0;
    int end = s.size() - 1;
    
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    
    return s;
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str); // Use getline to read the full input line

    vector<string> words;
    stringstream ss(str);
    string word;
    
    // Split string into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the words
    vector<string> reversedstring = reversestring(words);

    // Print the reversed words
    cout << "Reversed String: ";
    for (const string& w : reversedstring) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
