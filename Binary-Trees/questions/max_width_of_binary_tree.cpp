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

// time complexity is: O(n) space complexity is O(2^h)
//  intuition
// How to give no ?
// Observe the no. of each node. let's pick node (3) of 2nd level.  it's no. is 1 while left child = 3
// & right child = 4, Same if u observe for other nodes. currNode = n, leftChild = 2*n + 1, rightChild = 2*n + 2
// where root = 0
// While applying BFS alogwith nodes, store these
// no. as well in queue.

#define ll long long
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        int ans = INT_MIN;
        while (!q.empty())
        {
            auto node = q.front();
            int left = node.first;
            int right = INT_MIN;
            int si = q.size();
            for (int i = 0; i < si; i++)
            {
                auto rootnode = q.front();
                q.pop();
                TreeNode *temp = rootnode.second;
                int curr = rootnode.first;
                right = max(right, rootnode.first);
                if (temp->left != NULL)
                {
                    q.push({(ll)2 * curr + 1, temp->left});
                }
                if (temp->right != NULL)
                {
                    q.push({(ll)2 * curr + 2, temp->right});
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}