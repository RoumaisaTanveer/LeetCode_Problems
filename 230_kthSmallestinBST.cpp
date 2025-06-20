#include <iostream>
#include <vector>
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

void inorder(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> result;
    inorder(root, result);
    return result[k - 1];
}

int main()
{
    /*
        BST:
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;
    cout << "The " << k << "rd smallest element is: " << kthSmallest(root, k) << endl;

    return 0;
}
