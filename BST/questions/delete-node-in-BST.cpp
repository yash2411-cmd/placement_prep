#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* minval(TreeNode* root){
    TreeNode* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
        
    }
    return temp;
}
TreeNode* deletefromBST(TreeNode* root, int val){
    // bc
    if(root == NULL){
        return root;
    }
    if(root->val == val){
        // 0 child case 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child case
        if(root->left !=NULL && root->right==NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left ==NULL && root->right!=NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 childs case
        if(root->left!=NULL && root->right!=NULL){
            int min = minval(root->right)->val;
            root->val = min;
            root->right = deletefromBST(root->right, min);
            return root;
        }
    }
    else if(root->val >val){
            root->left= deleteNode(root->left,val);
            return root;
    }
    else{
        root->right = deleteNode(root->right,val);
        return root;
    }
    return root;

}
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletefromBST(root, key);
    }
};



int main()
{
 return 0;
}