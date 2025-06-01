#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        TreeNode *node = nullptr;
        for (int i = 0; i < levelSize; i++)
        {
            node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            cout << "hi" << node->val << endl;
        }
        if (node)
            result.push_back(node->val);
        cout << node->val << endl;
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

    vector<int> view = rightSideView(root);

    cout << "Right side view: ";
    for (int val : view)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}