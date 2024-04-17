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

// bfs solution
TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newRoot = new TreeNode(val);
        newRoot->left = root;
        return newRoot;
    }
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    while (level < depth - 1 && !q.empty())
    {
        int si = q.size();
        for (int i = 0; i < si; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        level++;
    }
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        TreeNode *newleft = new TreeNode(val);
        newleft->left = node->left;
        node->left = newleft;

        TreeNode *newright = new TreeNode(val);
        newright->right = node->right;
        node->right = newright;
    }
    return root;
}
int main()
{
    return 0;
}