#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int d){
        this->data = d;
        this->left= left;
        this->right = right;
    }

};

void levelordertraversal(Node* root){
      queue<Node*>q;
      q.push(root);
      q.push(NULL); // seprator

      while(!q.empty()){
        Node* temp = q.front();
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



Node* insertinBST(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertinBST(root->right,data);
    }
    else{
        root->left = insertinBST(root->left,data);

    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertinBST(root, data);
        cin>>data;
    }
    
}

void inorder(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    Node* root = NULL;
    cout<<"Enter data to create a BST: "<<endl;
    takeinput(root);
    cout<<"Printing BST: ";
    levelordertraversal(root);
    inorder(root);

 return 0;
}