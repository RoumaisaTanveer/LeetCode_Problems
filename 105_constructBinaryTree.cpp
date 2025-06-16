#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
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
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap[inorder[i]] = i;

        }
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode *helper(const vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return nullptr;
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        int index = inorderIndexMap[rootVal];
        root->left = helper(preorder, left, index - 1);
        root->right = helper(preorder, index + 1, right);

        return root;
    }
};