#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int number = 0;
    int sign = 1;

    for (size_t i = 0; i < s.length(); ++i) {
        char ch = s[i];

        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (ch == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (ch == '(') {
            // Push current result and sign for later
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * number;
            number = 0;
            result *= st.top(); st.pop(); // sign before parentheses
            result += st.top(); st.pop(); // result before parentheses
        }
        // Ignore spaces
    }

    result += sign * number;
    return result;
}

int main() {
    string s1 = "1 + 1";
    string s2 = " 2-1 + 2 ";
    string s3 = "(1+(4+5+2)-3)+(6+8)";

    cout << "Output 1: " << calculate(s1) << endl; // 2
    cout << "Output 2: " << calculate(s2) << endl; // 3
    cout << "Output 3: " << calculate(s3) << endl; // 23

    return 0;
}
