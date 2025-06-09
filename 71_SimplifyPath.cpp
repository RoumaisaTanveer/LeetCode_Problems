#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    vector<string> stack;
    stringstream ss(path);
    string part;

    while (getline(ss, part, '/'))
    {
        if (part == "" || part == ".")
        {
            continue; //current directory is skipped
        }
        else if (part == "..")
        {
            if (!stack.empty())
                stack.pop_back(); 
                //means if we have .. we go to previous directory means popping this to change path
        }
        else
        {
            stack.push_back(part); // and push the next part
        }
    }

    string result = "/";
    for (int i = 0; i < stack.size(); i++)
    {
        result += stack[i];
        if (i != stack.size() - 1)
            result += "/"; //adds slash after each dir except last 
    }

    return result;
}
int main()
{
    return 0;
}