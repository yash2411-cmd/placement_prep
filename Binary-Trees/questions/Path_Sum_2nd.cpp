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

// given a binary tree find all the paths from root to leaf whose sum adds upto the given targetSum.
class Solution
{
public:
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> path)
    {
        if (root == NULL)
        {
            return;
        }
        // push the current root valeu into our path
        path.push_back(root->val);

        // we check if we have reached at a leaf node and our target sum is equal to that node so we have found our ans
        if (root->left == NULL && root->right == NULL && targetSum == root->val)
        {
            ans.push_back(path);
        }
        else
        { // recursive calls for the rest of the sub trees left and right
            solve(root->left, targetSum - root->val, ans, path);
            solve(root->right, targetSum - root->val, ans, path);
        }
        // we delete the element of the last npode before moving for the next calls
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, ans, path);
        return ans;
    }
};

int main()
{
    return 0;
}