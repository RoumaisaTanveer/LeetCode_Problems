#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *prev = nullptr;
    void flattenTree(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = prev;
        prev = root;
    }
    void flatten(TreeNode *root)
    {
        flattenTree(root);
    }
};
int main()
{
    return 0;
}