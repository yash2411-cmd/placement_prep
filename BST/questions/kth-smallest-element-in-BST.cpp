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
    void solve(TreeNode* root, int &i, int k, int &ans){
        // bc 
        if(root==NULL){
            return;
        }
        solve(root->left, i, k,ans);
        i++;
        if(i==k){
            ans = root->val;
            return;
        }
        solve(root->right,i,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans;
        solve(root,i ,k,ans);
        return ans;
    }
};

int main()
{
 return 0;
}