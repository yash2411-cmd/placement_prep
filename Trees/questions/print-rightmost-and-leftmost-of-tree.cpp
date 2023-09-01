#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            this->left = NULL;
            this->right = NULL;
        } 

};




void printCorner(Node *root)
{

    // solved using simple approach of level order traversal
    // The idea is to use Level Order Traversal. Every time we store the size of the queue in a variable n,
    // which is the number of nodes at that level. For every level we check three conditions,
    // whether there is one node or more than one node, in case there is only one node we print it
    // once and in case we have more than 1 nodes, we print the first (i.e node at index 0) and the 
    // node at last index (i.e node at index n-1).
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        
    int n= q.size();
    for(int i=0;i<n;i++){
        Node* temp = q.front();
        q.pop();
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        if(i==0){
            cout<<temp->data<<" ";
        }
        else{
            if(i==n-1){
                cout<<temp->data<<" ";
            }
        }
        
        }
    }
    
    

}


int main()
{
 return 0;
}