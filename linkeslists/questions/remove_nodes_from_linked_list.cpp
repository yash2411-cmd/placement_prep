#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextTemp = nullptr;

        while (current != nullptr)
        {
            nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        head = reverseList(head);
        int maxval = 0;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            maxval = max(maxval, curr->val);
            if (curr->val < maxval)
            {
                prev->next = curr->next;
                ListNode *del = curr;
                curr = curr->next;
                del->next = NULL;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(head);
    }
};

int main()
{
    return 0;
}