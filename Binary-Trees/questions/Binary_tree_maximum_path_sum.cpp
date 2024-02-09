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
//  */

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN; // Initialize with the smallest possible integer value

        maxPathSumHelper(root, maxSum);

        return maxSum;
    }

    int maxPathSumHelper(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
            return 0;

        int leftSum = max(0, maxPathSumHelper(root->left, maxSum));   // Max sum of the left subtree
        int rightSum = max(0, maxPathSumHelper(root->right, maxSum)); // Max sum of the right subtree

        // Update the maxSum by considering the sum including the current root
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        // Return the maximum sum of the path going down from the current node
        return root->val + max(leftSum, rightSum);
    }
};

int main()
{
    return 0;
}