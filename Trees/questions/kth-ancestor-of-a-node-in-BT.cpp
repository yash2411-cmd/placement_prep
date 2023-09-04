#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	struct Node *left, *right;
};

// your task is to complete this function
Node* solve(Node *root, int &k, int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* leftans = solve(root->left,k,node);
    Node* rightans = solve(root->right,k,node);
    
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            /// ans ko lock krne je liye humne isme max value dali
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            /// ans ko lock krne je liye humne isme max value dali
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans==NULL || ans->data ==node)return -1;
    else{
        return ans->data;
    }
    
}


int main()
{
 return 0;
}