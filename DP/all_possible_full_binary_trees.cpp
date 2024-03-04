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
    // with dp the time complexity is O(n^3) and without dp the time complexity is exponential.
    vector<TreeNode *> solve(int n, unordered_map<int, vector<TreeNode *>> &dp)
    {
        vector<TreeNode *> ans;
        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }
        if (n == 1)
        {
            ans.push_back(new TreeNode(0));
            return ans;
        }
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> lefttree = solve(i, dp);
            vector<TreeNode *> righttree = solve(n - 1 - i, dp);

            for (TreeNode *l : lefttree)
            {
                for (TreeNode *r : righttree)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return dp[n] = ans;
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
        {
            return {};
        }
        unordered_map<int, vector<TreeNode *>> dp;
        return solve(n, dp);
    }
};

int main()
{
    return 0;
}