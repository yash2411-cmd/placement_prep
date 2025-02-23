#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, int> prepostIndex;
    int index = 0;
    TreeNode solve(vector<int> &preorder, vector<int> &postorder, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }
        TreeNode root = new TreeNode(preorder[index++]);
        if (left == right)
        {
            return root;
        }

        int leftpart = preorder[index];
        int leftsubtree = prepostIndex[leftpart];

        root->left = solve(preorder, postorder, left, leftsubtree);
        root->right = solve(preorder, postorder, leftsubtree + 1, right - 1);

        return root;
    }
    TreeNode constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        for (int i = 0; i < preorder.size(); i++)
        {
            prepostIndex[postorder[i]] = i;
        }

        return solve(preorder, postorder, 0, preorder.size() - 1);
    }
};

int main()
{
    return 0;
}