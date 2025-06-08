 #include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // If it's a leaf node, check if the remaining sum equals the node's value
    if (!root->left && !root->right) {
        return targetSum == root->val;
    }

    // Recur on left and right subtrees with reduced sum
    int remaining = targetSum - root->val;
    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}
int main() {
    return 0;
}