// // In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

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
public:
    // approach one using extra space witn vector TC O(N) and SC O(N)
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int>sudo;
        int maxsum = 0;
        while(temp){
            sudo.push_back(temp->val);
            temp= temp->next;
        }
        int i=0; 
        int j= sudo.size()-1;
        while(i<j){
            maxsum= max(maxsum, sudo[i]+sudo[j]);
            i++;
            j--;
        }
        return maxsum;
    }


    // approach two using reverse TC O(N) and SC O(1)
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

    ListNode* getmid(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast!=NULL && fast->next != NULL){
            fast= fast->next->next;
            slow= slow->next;
        }
        return slow;

    }
    int pairSum(ListNode* head) {
        ListNode* mid = getmid(head);
        ListNode* prev= reverse(mid->next);
        int maxsum =0;
        ListNode* temp = head;
        while(prev){
            maxsum = max(maxsum, temp->val + prev->val);
            prev= prev->next;
            temp = temp->next;
        }
        return maxsum;
    }
};


int main()
{
 return 0;
}