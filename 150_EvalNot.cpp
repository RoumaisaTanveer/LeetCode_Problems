#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (const string &token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        }
        else
        {
            st.push(stoi(token));
        }
    }
    return st.top();
}
int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Output: " << evalRPN(tokens) << endl; // Output: 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Output: " << evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Output: " << evalRPN(tokens3) << endl; // Output: 22

    return 0;
}