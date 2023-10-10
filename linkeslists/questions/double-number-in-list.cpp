#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode * smallhead= reverse(head->next);
        head->next->next= head;
        head->next= NULL;
        return smallhead;
    }

    ListNode* doubleIt(ListNode* head) {
        // first we reverse the list because we need to handle the carry so we procede from last node
        head = reverse(head);
        // initialize some pointers to keep track of list
        ListNode* curr = head;
        int carry =0;
        ListNode* prev = NULL;
        // iterating over the nodes of linked list and making each node value to double
        while(curr!=NULL){
            // updated value of current node to its double + if any carry is there
            curr->val = curr->val * 2 + carry;
            // current will have the base value and the carry will shift to the next node
            carry = curr->val/10;
            // finding curr base value for ex if total is 18 then curr should have 8 and the one will be to carry
            curr ->val = curr->val %10;
            // moving pointers ahead 
            prev = curr;
            curr = curr->next;
        }
        // handling the case where a carry is left after traversing the whole list in this case we will need to make a new node and assign the carry to it
        if(carry>0){
            prev->next = new ListNode(carry);
        }
        // again reversing the list and return the original head of the list
        head = reverse(head);
        return head;

    }
};


int main()
{
 return 0;
}