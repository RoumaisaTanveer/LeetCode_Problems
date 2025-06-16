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
    int postIndex;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // Create a value -> index map for inorder
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;

        // Initialize postIndex to last element
        postIndex = postorder.size() - 1;

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode *helper(const vector<int> &inorder, const vector<int> &postorder, int left, int right)
    {
        if (left > right)
            return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);

        int index = inorderIndexMap[rootVal];
        root->left = helper(inorder, postorder, index + 1, right);
        root->left = helper(inorder, postorder, left, index - 1);

        return root;
    }
};