#include <bits/stdc++.h> 
using namespace std;
    // Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };



// approch for codestudio question 
Node* kReverse(Node* head, int k) {
    // Write your code here.
     // base case
        if(head==NULL){
            return NULL;
        }
        int count=0;
        Node* next= NULL;
        Node* prev= NULL;
        Node* curr= head;

        while(curr!=NULL && count < k){
            next = curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
            count++;
        }

        if(next!=NULL){
            head->next= kReverse(next, k);
        }
        
        return prev;
}


// approach for leetcode same question 
 int getlen(ListNode* head){
        int cnt=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

Node* reverseKGroup(Node* head, int k) {
        // base case
        int n = getlen(head);
        if(n<k){
            return head;
        }
        int count=0;
        Node* next= NULL;
        Node* prev= NULL;
        Node* curr= head;

        while(curr!=NULL && count < k){
            next = curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
            count++;
        }

        if(next!=NULL){
            head->next= reverseKGroup(next, k);
        }
        
        return prev;
        
    }