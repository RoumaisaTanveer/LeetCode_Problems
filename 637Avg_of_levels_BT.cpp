 #include <bits/stdc++.h>
using namespace std;
 vector<double> averageOfLevels(TreeNode* root) {
         vector<double> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size =q.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
int main() {
    return 0;
}