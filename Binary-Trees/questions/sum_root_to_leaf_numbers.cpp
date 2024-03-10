#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
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
    void dfs_paths(TreeNode *root, string path, vector<string> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(path);
            return;
        }

        dfs_paths(root->left, path, result);
        dfs_paths(root->right, path, result);
    }

    int sumNumbers(TreeNode *root)
    {
        vector<string> paths;
        dfs_paths(root, "", paths);

        int totalSum = 0;
        for (string numStr : paths)
        {
            totalSum += stoi(numStr);
        }

        return totalSum;
    }
};

int main()
{
    return 0;
}