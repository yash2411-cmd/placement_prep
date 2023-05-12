#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;


    // constructor similar to getnode
    Node(int data){
        this->data= data;
        this->next= NULL;
    }

    // destructor
    ~Node(){
        int value= this->data;
        if(this->next!= NULL){
            delete next;
            this->next= NULL;
        }
    }
};


void insertathead(Node* &head, int d ){
    Node* temp = new Node(d);
    temp->next= head;
    head= temp;

}

void insertattail(Node* tail, int d){
    Node* temp = new Node(d);
    if(tail==NULL){
        tail= temp;
        return;
    }
    tail->next= temp;
    tail= temp;
}

void insertatposition(Node* head,Node* tail, int index,int d){
    Node* temp = head;
    int cnt=1;
    if(index==1){
        insertathead(head,d);
    }
    while(cnt<index-1){
        temp= temp->next;
        cnt++;
    }
    Node* t = new Node(d);
    t->next= temp->next;
    temp->next= t;

    if(temp->next==NULL){
        insertattail(tail,d);
    }

    
}

Node* findmid(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}



void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* node1= new Node(21);
    Node* head= node1;
    print(head);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    insertathead(head, 24);
    print(head);

    Node* tail= node1;
    insertattail(tail, 15);
    print(head);

    insertatposition(head,tail, 2, 56);
    // print(head);

    insertatposition(head,tail, 5, 78);
    // print(head);
    insertatposition(head,tail, 6, 85);
    print(head);

    Node* mid= findmid(head);
    cout<<mid->data<<endl;

 return 0;
}