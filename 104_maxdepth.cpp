 int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int levelSize=q.size();
            while(levelSize--){
                TreeNode* node =q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
                depth++;
        }
            return depth;
    }