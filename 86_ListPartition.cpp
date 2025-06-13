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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *before_head = new ListNode(0);
        ListNode *after_head = new ListNode(0);
        ListNode *before = before_head;
        ListNode *after = after_head;   //make two lists less than and greater than x one
        while (head)
        {
            if (head->val < x)    //if value x less than head add to list beforehead else to after_head
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = nullptr;
        before->next = after_head->next;
        ListNode *result = before_head->next;  //connect both lists via before_head after_head using dummy to use next ptr
        delete after_head;
        delete before_head;

        return result;
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
    // Example
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(5);

    int n = 4; 

    Solution sol;
    ListNode *newHead = sol.partition(head,n);
    printList(newHead); 

    // Cleanup memory
    while (newHead)
    {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}
