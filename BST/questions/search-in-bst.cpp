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


// recursive way time complexity in worst case is O(n) and average is O(logn) but SC is O(height)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(val == root->val){
            return root;
        }
        if(root->val > val){
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);
        }
    }
};


// iterative way to optimize space complexity
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val == val){
                return temp;
            }
            if(temp->val < val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        return NULL;
    }
};



int main()
{
 return 0;
}