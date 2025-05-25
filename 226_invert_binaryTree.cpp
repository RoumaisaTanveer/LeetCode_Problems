#include <bits/stdc++.h>
using namespace std;
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}
int main()
{
    return 0;
}