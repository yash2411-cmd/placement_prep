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
    int sum;
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l= maxDepth(root->left);
        int r= maxDepth(root->right);

        return max(r,l)+1;
    }
    void solve(TreeNode* root, int depth, int currlevel){
        if(root!=NULL){
            if(currlevel == depth){
                sum += root->val; 
            }
            solve(root->left,depth,currlevel+1);
            solve(root->right,depth,currlevel+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int mxdpth = maxDepth(root);
        solve(root, mxdpth,1);
        return sum;
    }
};

int main()
{
 return 0;
}