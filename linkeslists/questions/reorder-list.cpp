#include<bits/stdc++.h>
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
class Solution {
public:
    ListNode* getmid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            // if(fast->next!=NULL){
            //     fast = fast->next;
            // }
            slow = slow->next;
        }
        // slow->next = NULL;
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // ListNode* temp = head;
        if(head->next == NULL || head==NULL || head->next->next==NULL){
            return;
        }
        
        ListNode* mid = getmid(head);
        ListNode* newNode = reverse(mid->next);
        mid->next = NULL;
        ListNode* first = head;
        ListNode* second = newNode;

        while(second!=NULL && first!=NULL){
            ListNode* next1= first->next;
            ListNode* next2= second->next;
            first->next = second;
            second->next = next1;
            first = next1;
            second= next2;
        }
    }
};

int main()
{
 return 0;
}