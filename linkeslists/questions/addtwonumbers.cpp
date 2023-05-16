#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    private:
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
    void insertattail(ListNode* &head, ListNode* &tail, int data){
        ListNode* temp = new ListNode(data);
        
        if(head==NULL){
            head= temp;
            tail = temp;
            return;
        }
        else{
            tail->next= temp;
            tail= temp;
        }
    }
    ListNode* add(ListNode* first, ListNode* second){
        int carry=0;
        ListNode* anshead= NULL;
        ListNode* anstail= NULL;
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL){
                val1= first->val;
            }
            int val2=0;
            if(second!=NULL){
                val2= second->val;
            }

            int sum = carry + val1 + val2;
            int digit= sum%10;
            // ListNode* temp = new ListNode(digit);
            // insert the digit node in ans linked list
            insertattail(anshead, anstail, digit); 

            carry = sum/10;
            if(first!=NULL){
                first= first->next;
            }
            if(second!=NULL){
                second= second->next;
            }
        }
        return anshead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // step 1 is to reverse both the lists
        l1= reverse(l1);
        l2= reverse(l2);

        // step 2 add the both lists
        ListNode* ans = add(l1,l2);

        // ans ko vapis reverse krdo
        // ans = reverse(ans);
        return ans; 
    }
};