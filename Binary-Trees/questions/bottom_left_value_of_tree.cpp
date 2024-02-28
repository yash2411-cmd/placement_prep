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
    // using BFS  to find the level order traversal of the tree the  time complexity is O(N) where N is number of nodes, the bfs traverse tree
    // in sorted order and the traversal goes from right to left
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *curr = root;
        q.push(curr);
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
        }
        return curr->val;
    }
};
int main()
{
    return 0;
}