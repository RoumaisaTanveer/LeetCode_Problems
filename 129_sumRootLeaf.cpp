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
    int dfs(TreeNode *node, int currentSum)
    {
        if (!node)
            return 0;
        currentSum = currentSum * 10 + node->val;

        if (!node->left && !node->right)
        {
            return currentSum;
        }
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
#include <iostream>
using namespace std;

// Assume Solution and TreeNode are already defined as in your code

int main()
{
    // Manually build the tree:
    //        1
    //       / \
    //      2   3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    int result = sol.sumNumbers(root);
    cout << "Sum of all root-to-leaf numbers: " << result << endl;

    // Clean up
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
