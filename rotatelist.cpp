#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    ListNode *tail = head;
    int length = 1;
    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    tail->next = head; // link last node to head
    k %= length;
    int stepsToNewTail = length - k;   //6-2 =4 
    ListNode *newTail = head;
    for (int i = 1; i < stepsToNewTail; ++i)
    {
        newTail = newTail->next;
    }
     ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}
int main()
{
    return 0;
}