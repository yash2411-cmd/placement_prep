#include<bits/stdc++.h>
using namespace std;

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


// brute force approach, with direct data change in original linked list

Node* sortList(Node *head)
{
    // Write your code here.
    int count0= 0;
    int count1= 0;
    int count2= 0;
    Node* temp = head;
    while(temp!=NULL){
      if (temp->data == 0) {
        count0++;
      } 
      else if (temp->data == 1)
        count1++;
      else if (temp->data == 2)
        count2++;
      temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(count0!=0){
            temp->data= 0;
            count0--;
        }
        else if(count1!=0){
            temp->data= 1;
            count1--;
        }
        else if(count2!=0){
            temp->data= 2;
            count2--;
        }
        temp= temp->next;
    }
    return head;

}


// approach two without data replacement in original linked list

void addelement(Node* &tail, Node* curr){
    tail->next= curr;
    tail= curr;
}

Node* sortList(Node *head)
{
    // Write your code here.
    Node* zerohead= new Node(-1);
    Node* onehead= new Node(-1);
    Node* twohead= new Node(-1);
    Node* zerotail= zerohead;
    Node* onetail= onehead;
    Node* twotail= twohead;
    
    Node* curr= head;
    // insert 0s, 1s, and 2s in 3 different list;
    while(curr!=NULL){
        int val= curr->data;
        if(val==0){
            addelement(zerotail, curr);
        }
        else if(val==1){
            addelement(onetail, curr);
        }
        else if(val==2){
            addelement(twotail, curr);
        }
        curr= curr->next;
    }
    
    // merging the three list
    if(onehead->next!=NULL){
        zerotail->next= onehead->next;
    }
    else{
        zerotail->next= twohead->next;
    }
    onetail->next= twohead->next;
    twotail->next= NULL;
    
    head= zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;
    
    return head;
    
    
}