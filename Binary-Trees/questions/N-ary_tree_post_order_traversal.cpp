#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    void post(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        for (auto ch : root->children)
        {
            post(ch, ans);
            ans.push_back(ch->val);
        }
    }
    vector<int> postorder(Node *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> ans;
        post(root, ans);
        ans.push_back(root->val);
        return ans;
    }
};

int main()
{
    return 0;
}