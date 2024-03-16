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
    int prev = 0;
    void in(TreeNode *&root)
    {
        if (root == NULL)
            return;
        in(root->right);
        root->val += prev;
        prev = root->val;
        in(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        in(root);
        return root;
    }
};

int main()
{
    return 0;
}