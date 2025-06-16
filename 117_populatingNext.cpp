#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        Node *curr = root;
        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (curr)
        {
            if (curr->left)
            {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right)
            {
                tail->next = curr->right;
                tail = tail->next;
            }
            curr = curr->next;

            // When current level is done
            if (!curr)
            {
                curr = dummy->next;
                dummy->next = nullptr;
                tail = dummy;
            }
        }

        return root;
    }

    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        Node *curr = root;
        Node *nxt = root->left;

        while (curr && nxt)
        {
            curr->left->next = curr->right;
            if (curr->next)
            {
                curr->right->next = curr->next->left;
            }

            curr = curr->next;
            if (!curr)
            {
                curr = nxt;
                nxt = curr->left;
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        Node *curr = root; // Current node at current level

        while (curr)
        {
            Node dummy(0); // Dummy node for next level
            Node *tail = &dummy;

            // Traverse current level
            while (curr)
            {
                if (curr->left)
                {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right)
                {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // Move to next node in current level
            }

            // Move to first node of next level
            curr = dummy.next;
        }

        return root;
    }
};
int main()
{
    return 0;
}