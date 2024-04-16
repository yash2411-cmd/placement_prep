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
    void solve(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *curr = new TreeNode(val);
            curr->left = root->left;
            root->left = curr;
            curr->right = NULL;
            TreeNode *curr2 = new TreeNode(val);
            curr2->right = root->right;
            root->right = curr2;
            curr2->left = NULL;
            return;
        }
        if (root->left)
        {
            solve(root->left, val, depth - 1);
        }
        if (root->right)
        {
            solve(root->right, val, depth - 1);
        }
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode *curr = new TreeNode(val);
            curr->left = root;
            curr->right = NULL;
            return curr;
        }
        solve(root, val, depth - 1);
        return root;
    }
};

int main()
{
    return 0;
}