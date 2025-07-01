
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> allValues;

        // Collect all values from all lists
        for (ListNode* head : lists) {
            while (head) {
                allValues.push_back(head->val);
                head = head->next;
            }
        }

        // Sort all values
        sort(allValues.begin(), allValues.end());

        // Build a new sorted linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        for (int val : allValues) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy.next;
    }


// Helper: Convert vector to linked list
ListNode* toList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}
};


 #include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}