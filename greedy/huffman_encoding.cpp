#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void traverse(Node *root, string temp, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }
        traverse(root->left, temp + '0', ans);
        traverse(root->right, temp + '1', ans);
    }
    vector<string> huffmanCodes(string S, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        string temp = "";
        traverse(root, temp, ans);
        return ans;
    }
};
int main()
{
    return 0;
}