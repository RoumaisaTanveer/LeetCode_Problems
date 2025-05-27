 #include <bits/stdc++.h>
using namespace std;
 int countNodes(TreeNode* root) {
        if (root==nullptr) return 0;

        int count=0;
          return 1 + countNodes(root->left) + countNodes(root->right);
    }
int main() {
    return 0;
}