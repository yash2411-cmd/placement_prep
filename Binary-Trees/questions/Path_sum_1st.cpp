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
// Given the root of a binary tree and an integer targetSum,
// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

class Solution
{
public:
    bool solve(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return targetSum == root->val;
        }
        return solve(root->left, targetSum - root->val) || solve(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool ispossible = solve(root, targetSum);
        return ispossible;
    }
};

int main()
{
    return 0;
}