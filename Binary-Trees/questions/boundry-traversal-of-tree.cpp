#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:

    void traverseleft(Node* root, vector<int>&ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseleft(root->left,ans);
        }
        else{
            traverseleft(root->right,ans);
        }        
    }
    
    void leaf(Node* root, vector<int> &ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }

    void traverseright(Node* root, vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            traverseright(root->right,ans);
        }else{
            traverseright(root->left,ans);
        }
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        traverseleft(root->left,ans);
        
        leaf(root->left,ans);
        leaf(root->right,ans);
        
        traverseright(root->right,ans);
            
        return ans;
        
        
        
    }
};

int main()
{
 return 0;
}