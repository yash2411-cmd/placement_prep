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
    // time complexity is O(nlogk) where n is the number of nodes, log k is time to check and store the k elements in heap
    // and space complexity is O(n+k) where n for storing nodes in queue and k is for storing sum in heap.
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> ans;
        queue<TreeNode *> q;
        // base case
        // if (root == NULL)
        //     return -1;
        q.push(root);
        // traversing over the queue
        while (!q.empty())
        {
            long long sum = 0; // created a row to store the nodes of current level
            int level = q.size();
            // processing the levels
            for (int i = 0; i < level; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push(sum);
            if (ans.size() > k)
            {
                ans.pop();
            }
        }
        // cout<<endl;
        if (ans.size() < k)
        {
            return -1;
        }
        return ans.top();
    }
};

int main()
{
    return 0;
}