#include<bits/stdc++.h>
using namespace std;


  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    // first way of doing same as the diameter question t.c is O(n^2)
    int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l= height(root->left);
        int r= height(root->right);

        return max(r,l)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        bool diff= abs(height(root->left)-height(root->right))<=1;

        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }


    // second way of doing optimized for t.c O(n)
     pair<bool,int> isBal(TreeNode* root) {
        if(root==NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        pair<int,int>left= isBal(root->left);
        pair<int,int>right= isBal(root->right);

        bool leftans= left.first;
        bool rightans= right.first;
        bool diff= abs(left.second - right.second)<=1;
        
        pair<bool,int>ans;
        ans.second = max(left.second,right.second)+1;
        if(leftans && rightans && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBal(root).first;
    }
};

int main()
{
 return 0;
}