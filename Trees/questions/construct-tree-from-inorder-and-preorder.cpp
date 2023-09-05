#include<bits/stdc++.h>
using namespace std;

// both of the solutions below are from using iterative approach
// gfg solution
struct Node
{
  int data;
  Node* left;
  Node* right;
};


class Solution {
public:
    Node* buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        return buildTreeHelper(in, pre, 0, n - 1, preIndex);
    }

private:
    Node* buildTreeHelper(int in[], int pre[], int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootData = pre[preIndex++];
        Node* root = new Node(rootData);
        // root->data = rootData;

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; ++i) {
            if (in[i] == rootData) {
                inIndex = i;
                break;
            }
        }

        root->left = buildTreeHelper(in, pre, inStart, inIndex - 1, preIndex);
        root->right = buildTreeHelper(in, pre, inIndex + 1, inEnd, preIndex);

        return root;
    }
};


// leetcode solution

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
    TreeNode * solve(vector<int> &preorder, vector<int> &inorder, int &index, int inorderstart, int inorderend){
        if(inorderstart>inorderend){
            return NULL;
        }
        int ele = preorder[index++];
        TreeNode* root = new TreeNode(ele);
        
        int pos = 0;
        for (int i = inorderstart; i <= inorderend; ++i) {
            if (inorder[i] == ele) {
                pos = i;
                break;
            }
        }
        
        root->left = solve(preorder, inorder, index, inorderstart, pos-1);
        root->right = solve(preorder, inorder, index, pos+1, inorderend);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(preorder, inorder, preindex, 0, n-1);
        return ans;
    }
};

int main()
{
 return 0;
}