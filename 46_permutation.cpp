 #include <bits/stdc++.h>
using namespace std;
class Solution {

        void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
            if(current.size()==nums.size()){
                result.push_back(current);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(used[i]) continue;


                used[i]=true;
                current.push_back(nums[i]);
                backtrack(nums,used,current,result);
                current.pop_back();
                used[i]=false;
            }
        }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;

        backtrack(nums, used, current, result);
        return result;
    }
};
int main() {
    return 0;
}