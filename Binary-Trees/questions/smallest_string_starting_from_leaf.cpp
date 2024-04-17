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
    //  time complexity of this is nearly O(n) and space complexity is almost constant
    void solve(TreeNode *root, string path, string &ans)
    {
        if (root == NULL)
        {
            return;
        }
        path = char(root->val + 'a') + path;
        if (root->left == NULL && root->right == NULL)
        {
            if (path < ans)
            {
                ans = path;
            }
        }
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        path.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "~";
        solve(root, "", ans);
        return ans;
    }
};

int main()
{
    return 0;
}