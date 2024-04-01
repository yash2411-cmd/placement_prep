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

// iterative approach :
vector<int> postorder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        for (auto ch : temp->children)
        {
            st.push(ch);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}