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
    //  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    //  {
    //      while (root)
    //      {
    //          if (p->val < root->val && q->val < root->val)
    //          {
    //              root = root->left;
    //          }
    //          else if (p->val > root->val && q->val > root->val)
    //          {
    //              root = root->right;
    //          }
    //          else
    //              return root;   //As soon as they split (one left, one right) or one equals root, you've found the LCA.
    //      }
    //      return nullptr;
    //  }

    // for binaryTRee
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root; // p and q found in different subtrees
        return left ? left : right;
    }

  
};
int main()
{
    // Manually build this BST:
    //       6
    //      / \
    //     2   8
    //    / \ / \
    //   0  4 7  9
    //     / \
    //    3   5

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = root->left;        // Node with val = 2
    TreeNode *q = root->left->right; // Node with val = 4

    Solution sol;
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}