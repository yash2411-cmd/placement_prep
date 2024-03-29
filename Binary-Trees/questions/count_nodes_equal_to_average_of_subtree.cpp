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

// time complexity is O(n) and space is O(H)
class Solution
{
public:
    pair<int, int> find(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> left_subtree = find(root->left);
        pair<int, int> right_subtree = find(root->right);
        int sum = left_subtree.first + right_subtree.first + root->val;
        int count = left_subtree.second + right_subtree.second + 1;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int cnt = 0;
        pair<int, int> ans = find(root);
        int sum = ans.first;
        int count = ans.second;
        if (sum / count == root->val)
        {
            cnt++;
        }
        cnt += averageOfSubtree(root->left);
        cnt += averageOfSubtree(root->right);
        return cnt;
    }
};

// optimized time O(n) and space O(1)
class Solution
{
public:
    struct subtree
    {
        int sum;
        int cnt;
    };
    subtree find(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return {0, 0};
        subtree left_subtree = find(root->left, ans);
        subtree right_subtree = find(root->right, ans);
        int sum = left_subtree.sum + right_subtree.sum + root->val;
        int count = left_subtree.cnt + right_subtree.cnt + 1;
        if (sum / count == root->val)
        {
            ans++;
        }
        return {sum, count};
    }
    int averageOfSubtree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int res = 0;
        find(root, res);
        return res;
    }
};

int main()
{
    return 0;
}