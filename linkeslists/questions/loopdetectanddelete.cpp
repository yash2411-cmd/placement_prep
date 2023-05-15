#include<bits/stdc++.h>
using namespace std;
    
// codestudio
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

Node* floydalgo(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow= head;
    Node* fast= head;
    while(slow!=NULL && fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }
        slow= slow->next;

        if(slow==fast){
            return slow;
        }
    }
    return NULL;

}

Node* getstartingnode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection= floydalgo(head);
    if(intersection==NULL)return NULL;
    Node* slow= head;
    // slow= head;
    while(slow!=intersection){
        slow= slow->next;
        intersection= intersection->next;
    }
    return slow;
}


Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL){
        return NULL;
    }
    Node* startpoint= getstartingnode(head);
    if(startpoint==NULL)return head;
    Node* temp = startpoint;
    while(temp->next !=startpoint){
        temp = temp->next;
    }
    temp->next= NULL;
    return head;
}