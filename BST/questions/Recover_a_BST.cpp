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
    void recoverTree(TreeNode *root)
    {
        // using morris traversal time O(n) space O(1);
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                // check if we found a fasle pair that is swapped
                if (prev != NULL && root->val < prev->val)
                {
                    if (first == NULL)
                    {
                        // store the nodes to be swapped
                        first = prev;
                        second = root;
                    }
                    else
                    {
                        second = root;
                    }
                }
                prev = root;
                root = root->right;
            }
            else
            {
                TreeNode *temp = root->left;
                // finding predecessor
                while (temp->right != NULL && temp->right != root)
                {
                    temp = temp->right;
                }

                if (temp->right == NULL)
                {
                    temp->right = root;
                    root = root->left;
                }
                else
                {
                    temp->right = NULL;

                    // check for swapped values
                    if (prev != NULL && root->val < prev->val)
                    {
                        if (first == NULL)
                        {
                            // store the nodes to be swapped
                            first = prev;
                            second = root;
                        }
                        else
                        {
                            second = root;
                        }
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};

int main()
{
    return 0;
}