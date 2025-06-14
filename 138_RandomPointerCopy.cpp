#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;

        // Step 1: Interleave copied nodes between original nodes
        while (curr)
        {
            Node *newNode = new Node(curr->val); // a new node is created with same value as our current node
            newNode->next = curr->next;          // it is positioned next to current node and it points to curr ka next node
            curr->next = newNode;                // curr ka next points to new node as it is interleaved
            curr = newNode->next;                // and we traverse to next node that is curr->next but now newNode->next
        }

        curr = head;

        // Step 2: Assign random pointers to the copied nodes
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next; // copied node ka random points to copied version of curr's random
            }
            curr = curr->next->next; // skip to next original node (since we interleaved, curr->next is the copy)
        }

        curr = head;
        Node *dummyHead = new Node(0); // dummy head to help return copied list
        Node *copyCurr = dummyHead;

        // Step 3: Separate original and copied nodes into two lists
        while (curr)
        {
            Node *copied = curr->next;         // copied node is curr->next
            curr->next = copied->next;         // restore original list by skipping the copied node
            copyCurr->next = copied;           // attach copied node to copied list
            copyCurr = copied;                 // move pointer forward in copied list
            curr = curr->next;                 // move to next original node
        }

        return dummyHead->next; // return head of copied list
    }
};
