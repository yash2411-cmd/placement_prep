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


bool floydalgo(Node* head){
    if(head==NULL){
        return false;
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
            return true;
        }
    }
    return false;

}

int main()
{
 return 0;
}