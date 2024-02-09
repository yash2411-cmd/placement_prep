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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        // base case
        if (root == NULL)
            return ans;
        q.push(root);
        // traversing over the queue
        while (!q.empty())
        {
            vector<int> row; // created a row to store the nodes of current level
            int level = q.size();
            // processing the levels
            for (int i = 0; i < level; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main()
{
    return 0;
}