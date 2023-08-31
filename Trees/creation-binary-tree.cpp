#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data=data;
            this->left = NULL;
            this->right = NULL;
        } 

};

node * buildTree(node* root){

    cout<<"Enter data for root node: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    // cout<<endl;
    cout<<"Enter data for left Node: "<<data<<endl;
 
    root->left = buildTree(root->left);
    
    cout<<"Enter data for right Node: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
} 

// level order traversal, it prints nodes by levels until it finds all null;s
void levelordertraversal(node* root){
      queue<node*>q;
      q.push(root);
      q.push(NULL); // seprator

      while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            // means purana level end ho chuka hai 
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

      }
}

void inorder(node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    //LRN
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"printing level order of binary tree: ";
    cout<<endl;
    levelordertraversal(root);
       cout<<"inorder traversal"<<endl;
       inorder(root);
       cout<<endl;
       cout<<"preorder traversal"<<endl;
       preorder(root);
       cout<<endl;
       cout<<"postorder traversal"<<endl;
       postorder(root);
 return 0;
}