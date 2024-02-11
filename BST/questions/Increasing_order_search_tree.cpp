#include <bits/stdc++.h>
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
class Solution
{
public:
    void traverse_inorder(TreeNode *root, TreeNode *&newroot, TreeNode *&currnode)
    {
        if (root == NULL)
        {
            return;
        }
        traverse_inorder(root->left, newroot, currnode);
        if (newroot == NULL)
        {
            newroot = root;
            currnode = newroot;
        }
        else
        {
            currnode->right = root;
            root->left = NULL;
            currnode = currnode->right;
        }
        TreeNode *temp = root->right; // Store the right child temporarily
        root->right = nullptr;
        traverse_inorder(root->right, newroot, currnode);
        // return newroot;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *newroot = NULL;
        TreeNode *currnode = NULL;
        traverse_inorder(root, newroot, currnode);
        return newroot;
    }
};

int main()
{
    return 0;
}