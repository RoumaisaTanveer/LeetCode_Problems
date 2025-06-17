#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    // recursive for BST only
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     if (p->val < root->val && q->val < root->val)
    //     {
    //         return lowestCommonAncestor(root->left, p, q);
    //     }
    //     else if (p->val > root->val && q->val > root->val)
    //     {
    //         return lowestCommonAncestor(root->right, p, q);
    //     }
    //     else
    //         return root;
    // }

   // Iterative for BST
     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
                return root; // As soon as they split (one left, one right) or one equals root, you've found the LCA.
        }
        return nullptr;
    }
};