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

Node * minval(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
        
    }
    return temp;
}
Node * maxval(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
        
    }
    return temp;
}


Node* deletefromBST(Node* root, int val){
    // bc
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        // 0 child case 
        if(root-left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child case
        if(root->left !=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left ==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 childs case
        if(root->left!=NULL && root->right!=NULL){
            int min = minval(root->right)->data;
            root->data = min;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
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
    // insertinBST(root);
    cout<<"Printing BST: ";
    // levelordertraversal(root);
    // inorder(root);
    cout<<minval(root);
    cout<<maxval(root);
 return 0;
}