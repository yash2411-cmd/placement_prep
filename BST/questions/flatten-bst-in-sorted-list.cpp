#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
// codestudio solution
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int> *root, vector<int> &in)
{
    // LNR
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)

        return NULL;

    vector<int> in;

    inorder(root, in);

    // sort(in.begin(), in.end());

    TreeNode<int> *head = new TreeNode<int>(in[0]);

    head->left = NULL;

    head->right = NULL;

    TreeNode<int> *last = head;

    int i = 1;

    for (i = 1; i < in.size(); i++)

    {

        TreeNode<int> *t = new TreeNode<int>(in[i]);

        t->right = NULL;

        t->left = NULL;

        last->left = t;

        last = t;
    }

    return head;
}

int main()
{
    return 0;
}