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

void insertwithvalue(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* curr= tail;
        while(curr->data != element){
            curr= curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
        
    }
}

void deletenode(Node* &tail, int value){
    if(tail==NULL)return;
    else{
        Node* prev= tail;
        Node* curr= prev->next;
        while(curr->data!=value){
            prev= curr;
            curr = curr->next;
        }
        prev->next= curr->next;
        if(curr==prev){
            tail = NULL;
            return;
        }
        if(tail==curr){
            tail= prev;
        }
        curr->next= NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp= tail;
    if(tail == NULL){
        cout<<"list is empty."<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail= tail->next;
    } while (tail!=temp);
    cout<<endl;
    
}


int main()
{

    Node* tail = NULL;
    insertwithvalue(tail, 5, 3);
    print(tail);
    insertwithvalue(tail, 3, 5);
    print(tail);
    insertwithvalue(tail, 5, 8);
    print(tail);
    insertwithvalue(tail, 8, 90);
    print(tail);

    deletenode(tail, 8);
    print(tail);
 return 0;
}