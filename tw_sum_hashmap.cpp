 #include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int>num_index;
            for(int i=0;i<nums.size();i++){
                int it =target-nums[i];
                if(num_index.find(it)!=num_index.end()){
                    return{num_index[it],i};
                }
                num_index[nums[i]] = i; 
        }
        return {};
        }
        
    };
int main() {
    return 0;
}