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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *front1 = list1;
        ListNode *end1 = list1;
        int cnt = 0;
        while (cnt < a - 1)
        {
            front1 = front1->next;
            cnt++;
        }
        cnt = 0;
        while (cnt < b)
        {
            end1 = end1->next;
            cnt++;
        }
        ListNode *end2 = list2;
        while (end2->next != NULL)
        {
            end2 = end2->next;
        }
        front1->next = list2;
        end2->next = end1->next;
        return list1;
    }
};

int main()
{
    return 0;
}