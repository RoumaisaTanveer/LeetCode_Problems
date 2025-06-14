#include <bits/stdc++.h>
using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        return false;
}

int main()
{
    return 0;
}