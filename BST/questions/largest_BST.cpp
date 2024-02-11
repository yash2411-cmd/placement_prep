#include <bits/stdc++.h>
using namespace std;

// this is the codestudio version where we need to return the size of largest BST
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info
{
public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(TreeNode *root, int &maxsize)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, maxsize);
    info right = solve(root->right, maxsize);

    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data, right.maxi);
    currnode.mini = min(root->data, left.mini);

    if (left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini))
    {
        currnode.isbst = true;
    }
    else
    {
        currnode.isbst = false;
    }
    if (currnode.isbst)
    {
        maxsize = max(maxsize, currnode.size);
    }
    return currnode;
}

int largestBST(TreeNode *root)
{
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}

// leetcode solution : we have to return the maximum sum of largest BST in the binarytree
static int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();
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
class info
{
public:
    int maxi;
    int mini;
    bool isbst;
    int sum;
};

class Solution
{
public:
    info solve(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            return {INT_MIN, INT_MAX, true, 0};
        }
        info left = solve(root->left, sum);
        info right = solve(root->right, sum);

        info currnode;
        currnode.sum = root->val + left.sum + right.sum;
        currnode.maxi = max(root->val, right.maxi);
        currnode.mini = min(root->val, left.mini);

        if (left.isbst && right.isbst && (root->val > left.maxi && root->val < right.mini))
        {
            currnode.isbst = true;
        }
        else
        {
            currnode.isbst = false;
        }
        if (currnode.isbst)
        {
            sum = max(sum, currnode.sum);
        }
        return currnode;
    }

    int maxSumBST(TreeNode *root)
    {
        int maxsum = 0;
        info temp = solve(root, maxsum);
        return maxsum;
    }
};

int main()
{
    return 0;
}