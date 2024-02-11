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
    void inorder(TreeNode *root, vector<int> &in)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    vector<int> mergearray(vector<int> a, vector<int> b)
    {
        vector<int> ans(a.size() + b.size());
        int i = 0, k = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
            {
                ans[k++] = a[i];
                i++;
            }
            else
            {
                ans[k++] = b[j];
                j++
            }
        }
        while (i < a.size())
        {
            ans[k++] = a[i];
            i++;
        }
        while (j < b.size())
        {
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }

    TreeNode *IN_to_BST(int s, int e, vector<int> &in)
    {
        if (s > e)
        {
            return NULL;
        }
        int mid = (s + e) / 2;
        TreeNode *root = new TreeNode(in[mid]);
        root->left = IN_to_BST(s, mid - 1, in);
        root->right = IN_to_BST(mid + 1, e, in);

        return root;
    }

    // second way to use double linked list approach to optimize the space

    void convertToDLL(TreeNode *root, TreeLinkNode *&head)
    {
        if (root == NULL)
        {
            return NULL;
        }
        convertToDLL(root->right, head);
        root->right = head;
        if (head != NULL)
        {
            head->left = root;
        }
        head = root;
        convertToDLL(root->left, head);
    }

    // merge two sorted linked lists
    TreeLinkNode *mergeTwoLists(TreeLinkNode *l1, TreeLinkNode *l2)
    {
        TreeLinkNode *head = NULL;
        TreeLinkNode *tail = NULL;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (!head)
                {
                    head = tail = l1;
                    l1 = l1->right;
                }
                else
                {
                    tail->right = l1;
                    l1->left = tail;
                    tail = l1;
                    l1 = l1->right;
                }
            }
            else
            {
                if (!head)
                {
                    head = tail = l2;
                    l2 = l2->right;
                }
                else
                {
                    tail->right = l2;
                    l2->left = tail;
                    tail = l2;
                    l2 = l2->right;
                }
            }
        }
        while (l1 != NULL)
        {
            tail->right = l1;
            l1->left = tail;
            tail = l1;
            l1 = l1->right;
        }
        while (l2 != NULL)
        {
            tail->right = l2;
            l2->left = tail;
            tail = l2;
            l2 = l2->right;
        }
        return head;
    }
    int countnodes(TreeNode *head)
    {
        int cnt = 0;
        TreeNode *temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }

    // convert sorted linked list to BST
    // create leftsubtree by the first n/2 nodes of linked list
    // create the root node and connect the leftsubtree to it
    // now , the right subtree is formed by the next n/2 nodes in the linkedlist.
    TreeNode *sortedListToBST(ListNode *head, int n)
    {
        // remaining nodes for right part will be n- n/2 -1;
        if (n <= 0 || root == NULL)
        {
            return NULL;
        }
        TreeNode *left = sortedListToBST(head, n / 2);
        TreeNode *root = head;
        root->left = left;
        head = head->next;
        root->right = sortedListToBST(head, n - n / 2 - 1);
        return root;
    }

    TreeNode *MergeBST(TreeNode *root1, TreeNode *root2)
    {
        // vector<int> Bst1;
        // vector<int> Bst2;
        // inorder(root1, Bst1);
        // inorder(root2, Bst2);
        // // sort(in.begin(),in.end());

        // vector<int> mergeArray = mergearray(Bst1, Bst2);
        // int s = 0, e = mergeArray.size() - 1;
        // return IN_to_BST(s, e, mergeArray);

        // second way optimized for space complexity
        TreeNode *head1 = NULL;
        convertToDLL(root1, head1);
        head1->left = NULL;

        TreeNode *head2 = NULL;
        convertToDLL(root2, head2);
        head2->left = NULL;

        TreeNode *head = mergeTwoLists(head1, head2);
        int n = countnodes(head);
        return sortedListToBST(head, n);
    }
};

int main()
{
    return 0;
}