#include<bits/stdc++.h>
using namespace std;


  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        // ListNode* after(0);
        ListNode* curr_before= before;
        ListNode* curr_after= after;

        while(head){
            if(head->val < x){
                curr_before->next = head;
                curr_before= head;
            }
            else{
                curr_after->next = head;
                curr_after = head;
            }
            head = head->next;
        }

        curr_after->next= nullptr;
        curr_before->next= after->next;

        return before->next;



    }
};


int main()
{
 return 0;
}