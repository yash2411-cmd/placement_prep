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

void deleteatpos(Node* &head, int pos){
    // Node* temp = head;
    int cnt=1;
    if(pos==1){
        Node* t= head;
        head= head->next;
        t->next= NULL;
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
        prev->next= curr->next;
        curr->next= NULL;
        delete curr;
    }

}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

bool iscircular(Node* head){
    // for empty list also we consider it to be a circular one 
    if(head == NULL)return true;
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp= temp->next;
    }
    if(temp==NULL)return false;
    else return true;
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
    print(head);

    insertatposition(head,tail, 5, 78);
    print(head);

    deleteatpos(head,1);
    print(head);

    if(iscircular(head)){
        cout<<"list is circular. "<<endl;
    }
    else{
        cout<<"list is Not circular. "<<endl;
    }

 return 0;
}