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
    int minDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        // checking for if there is only single level after the node
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        // calling function if the right or left subtree is not null
        int l = root->left != NULL ? minDepth(root->left) : INT_MAX;
        int r = root->right != NULL ? minDepth(root->right) : INT_MAX;

        // returning the minimum number of nodes from left or right subtree
        return min(l, r) + 1;
    }

    // second wyay to do it
    int mindepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = mindepth(root->left);
        int r = mindepth(root->right);
        if (l == 0 || r == 0)
        {
            return max(l, r) + 1;
        }
        // root->left = NULL;
        // root->right = NULL;
        return min(r, l) + 1;
    }
};

int main()
{
    return 0;
}