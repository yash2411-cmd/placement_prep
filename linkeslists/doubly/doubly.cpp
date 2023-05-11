#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int d){
        this->data= d;
        this->next= NULL;
        this->prev= NULL;
    }
};

void getlen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp= temp->next;
    }
    cout<<"length of list is: "<<len<<endl;
}

void insertathead(Node* &head,Node* &tail, int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head= temp; 
        tail= temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next= head;
        head->prev= temp;
        head= temp;

    }
}

void insertattail(Node* &tail,Node* &head, int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail= temp;
        head= temp; 
    }
    else{
    Node* temp = new Node(d);
    tail->next= temp;
    temp->prev= tail;   
    tail= temp;

    }
}

void insertat(Node* &head, Node* &tail, int pos, int d){
    int cnt =1;
    Node* temp = head;
    if(pos==1){
        insertathead(head,tail,d);
        return;
    }
    while(cnt<pos){
        temp= temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }
    Node* nodetoinsert= new Node(d);
    nodetoinsert->next= temp->next;
    temp->next->prev= nodetoinsert;
    temp->next= nodetoinsert;
    nodetoinsert->prev= temp;
}

void deleteatpos(Node* &head, int pos){
    // Node* temp = head;
    int cnt=1;
    if(pos==1){
        Node* t= head;
        t->next->prev= NULL;
        t->next= NULL;
        head= t->next;
        delete t;
    }
    else{
        Node* curr= head;
        Node* prev= NULL;
        int cnt=1;
        while(cnt<pos){
            prev= curr;
            curr= curr->next;
            cnt++;
        }
        
        curr->prev= NULL;
        prev->next= curr->next;
        curr->next= NULL;
        delete curr;
    }

}


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        }
        cout<<endl;
        
}

int main()
{
    Node* node1= new Node(18);
    Node* head= node1;
    Node* tail= node1;


    print(head);
    insertathead(head,tail,78);
    print(head);
    insertattail(tail,head, 80);
    print(head);

    insertat(head, tail, 3, 24);
    print(head);
    getlen(head);
    deleteatpos(head, 3);
    print(head);
 return 0;
}