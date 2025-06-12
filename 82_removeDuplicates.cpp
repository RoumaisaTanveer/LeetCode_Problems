#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head); // Dummy before head
        ListNode *prev = &dummy; // Points to last node in result
        ListNode *curr = head;

        while (curr)
        {
            bool isDuplicate = false;

            // Skip all nodes with the same value
            while (curr->next && curr->val == curr->next->val)
            {
                isDuplicate = true;
                ListNode *temp = curr;
                curr = curr->next;
                delete temp; // optional: free memory
            }

            if (isDuplicate)
            {
                // Also delete the last one in duplicate group
                ListNode *temp = curr;
                curr = curr->next;
                delete temp;
                continue; // don't move prev
            }

            // No duplicates → link it
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr; // terminate the list
        return dummy.next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example list: 1 -> 2 -> 2 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // int n = 2; // Remove 2nd node from the end (which is 4)

    Solution sol;
    ListNode *newHead = sol.deleteDuplicates(head);

    printList(newHead); // Output: 1 2 3 5

    // Cleanup memory
    while (newHead)
    {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}
