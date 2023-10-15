#include<bits/stdc++.h>
using namespace std;
\/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = new ListNode(NULL);
        ListNode* curr = head;


        while(curr!=NULL){
            ListNode* prev = sorted;

            while(prev->next !=NULL && prev->next->val <= curr->val){
                prev= prev->next;
            }
            ListNode* next = curr->next;
            curr->next = prev->next;
            prev->next = curr;

            curr= next;

        }
    return sorted->next;
    }
};

int main()
{
 return 0;
}