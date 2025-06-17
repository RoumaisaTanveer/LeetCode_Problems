#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
    stack<TreeNode *> stk;

    void pushLeft(TreeNode *root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode *node = stk.top();
        stk.pop();
        if (node->right)
        {
            pushLeft(node->right); // agr right ha to uska b pushleft kr do saaary left child push
        }
        return node->val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

int main()
{
    // Tree:
    //      7
    //     / \
    //    3   15
    //        / \
    //       9  20

    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *obj = new BSTIterator(root);
    while (obj->hasNext())
    {
        cout << obj->next() << " ";
    }

    // Expected output: 3 7 9 15 20
    return 0;
}
