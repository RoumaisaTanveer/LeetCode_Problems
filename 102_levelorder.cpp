#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

TreeNode *buildExampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    return root;
}

int main()
{
    TreeNode *root = buildExampleTree();

    vector<vector<int>> levels = levelOrder(root);

    cout << "Level order traversal:\n";
    for (const auto &level : levels)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        }

    return 0;
}
