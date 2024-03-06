#include <bits/stdc++.h>
using namespace std;

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = rangeSumBST(root->left, low, high);
    int right = rangeSumBST(root->right, low, high);
    int sum = 0;
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
    }
    return sum + right + left;
}

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return NULL;
    }
    vector<int> ans;
    inorder(root, ans);
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] >= low && ans[i] <= high)
        {
            sum += ans[i];
        }
    }
    return sum;
}

int main()
{
    return 0;
}