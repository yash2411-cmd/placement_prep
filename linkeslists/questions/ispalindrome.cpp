#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
private: 
    /// function to find the middle of list
    ListNode* getmid(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast!=NULL && fast->next != NULL){
            fast= fast->next->next;
            slow= slow->next;
        }
        return slow;

    }
    // function to reverse the list after mid
    ListNode* reverse(ListNode* head){
        ListNode* curr= head;
        ListNode* next= NULL;
        ListNode* prev= NULL;
        while(curr!=NULL){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // if list contains only 1 element then it is palindrome
        if(head->next==NULL)return 1; 
        
        // get mid and make a temp node next to mid element for reversing
        ListNode* mid=  getmid(head);
        ListNode* temp= mid->next;

        // reversing the list after mid index
        mid->next= reverse(temp);

        // compairing the two halves of list
        ListNode* head1= head;
        ListNode* head2= mid->next;
        while(head2!=NULL){
            if(head1->val != head2->val){
                return 0;
            }
            head1= head1->next;
            head2= head2->next;
        }
        temp= mid->next;
        // again performing reverse to maintain the original linked list
        mid->next = reverse(temp);
        return 1;

    }
};

int main()
{
 return 0;
}