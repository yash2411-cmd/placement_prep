// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.


#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// approach #1 using map to clone the list with random pointer TC O(N) SC O(N)
class Solutionone {
private: 
    void insertattail(Node*& head,Node*& tail, int d){
        Node* data= new Node(d);
        if(head==NULL){
            head = data;
            tail = data;
            return;
        }
        else{
            tail->next= data;
            tail = data;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead= NULL;
        Node* clonetail= NULL;
        Node* temp = head;

        // make the clone of original given list
        while(temp!=NULL){
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // step 2 is to make a mapping from original list to cloned list
        unordered_map<Node*, Node*>clonemap;
        temp = head;
        Node* temp2= clonehead;
        while(temp!=NULL && temp2!=NULL){
            clonemap[temp] = temp2;
            temp = temp->next;
            temp2= temp2->next;
        }

        // step 3 is to apply the expression clone->random = clonemap[original->random]
        temp = head;
        temp2 = clonehead;
        while(temp!=NULL && temp2!=NULL){
            temp2->random = clonemap[temp->random];
            temp= temp->next;
            temp2= temp2->next;
        }
        return clonehead;
        
    }
};


// approach 2 changing links itself so TC O(N) and SC O(1) -> optimized approach
class Solutiontwo {
private:
    void insertattail(Node*& head,Node*& tail, int d){
        Node* data= new Node(d);
        if(head==NULL){
            head = data;
            tail = data;
            return;
        }
        else{
            tail->next= data;
            tail = data;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // step 1 clone list
        Node* clonehead= NULL;
        Node* clonetail= NULL;
        Node* temp = head;

        // make the clone of original given list
        while(temp!=NULL){
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // step 2 change the links and put clone nodes in between original nodes
        Node* originalnode= head;
        Node* clonenode= clonehead;

        while(originalnode!=NULL && clonenode!= NULL){
            Node* next = originalnode->next;
            originalnode->next = clonenode;
            originalnode = next;

            next = clonenode->next;
            clonenode->next= originalnode;
            clonenode= next;
        }

        // step 3 random pointer copy 
        temp= head;
        while(temp!=NULL){
            if(temp->next!=NULL ){
                temp->next->random= temp->random ? temp->random->next:  temp ->random;
            }
            temp = temp->next->next; // do baar aage badana hai taki hum original list ke next pointer pr chle jai
        }
        
        // step 4 change ko revert krdo step 2 ke
        originalnode= head;
        clonenode= clonehead;
        while(originalnode!=NULL && clonenode!= NULL){
            originalnode->next= clonenode->next;
            originalnode= originalnode->next;

            if(originalnode!=NULL){
                clonenode->next= originalnode->next;
            }
            clonenode= clonenode->next;
        }

        // return ans
        return clonehead;       
    }
};


int main()
{
 return 0;
}