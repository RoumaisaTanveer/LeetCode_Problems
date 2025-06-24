class Solution {
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result){
        if(current.size()==k){
            result.push_back(current);
            return;
        }
        for(int i=start;i<=n;i++){
            current.push_back(i);
            backtrack(i+1,n,k,current,result);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>current;
        backtrack(1,n,k,current,result);
        return result;
    }
};

 #include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}