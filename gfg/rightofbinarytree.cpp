#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(vector<int>&ans, Node *root, int cnt){
        if(!root)return;
        if(ans.size()== cnt){
            ans.push_back(root->data);
        }
        solve(ans, root->right, cnt+1);
        solve(ans, root->left, cnt+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       if(!root)return ans;
       solve(ans, root,0);
       return ans;
    }
};

int main()
{
 return 0;
}