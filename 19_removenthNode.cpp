#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        ListNode* tracker = dummy;

       
        for (int i = 0; i <= n; i++) {
            curr = curr->next;
        }

      
        while (curr != nullptr) {
            curr = curr->next;
            tracker = tracker->next;
        }

        // Delete the nth node from end
        ListNode* temp = tracker->next;
        tracker->next = tracker->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove 2nd node from the end (which is 4)

    Solution sol;
    ListNode *newHead = sol.removeNthFromEnd(head, n);

    printList(newHead); // Output: 1 2 3 5

    // Cleanup memory
    while (newHead) {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}
