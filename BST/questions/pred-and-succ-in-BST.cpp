#include<bits/stdc++.h>
using namespace std;


/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode *temp = root;
    int pre =-1;
    int suc=-1;
        while(temp!=NULL && temp->data!=key){
            if(temp->data > key){
                suc = temp->data;
                temp= temp->left;
            }
            else{
                pre = temp->data;
                temp = temp->right;
            }
        }
        if(temp!=NULL){

        TreeNode* lefttree = temp->left;
        while(lefttree!=NULL){
            pre = lefttree->data;
            lefttree = lefttree->right;
        }
        TreeNode* righttree = temp->right;
        while(righttree!=NULL){
            suc = righttree->data;
            righttree = righttree->left;
        }
        }
        pair<int,int> ans = make_pair(pre,suc);

        return ans;
        
}

int main()
{
 return 0;
}