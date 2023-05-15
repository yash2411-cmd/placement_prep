// leetcode daily challenge 15-05-23
// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // using two pointer approch
        ListNode* r= head;
        ListNode* l= head;

        for( int i=0;i<k-1;i++){
            r= r->next;
        }
        ListNode* swapNode= r;
        while(r->next!=NULL){
            l= l->next;
            r= r->next;
        }
        swap(swapNode->val, l->val);

        return head;
    }
};



int main()
{


 return 0;
}