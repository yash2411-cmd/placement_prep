#include<bits/stdc++.h>
using namespace std;


// solution for gfg
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontnode->data);
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
            
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};



// solution for leetcode
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>ans;
        map<int,map<int,multiset<int>>> nodes;
         queue<pair<TreeNode*,pair<int,int>>>q;

         q.push(make_pair(root,make_pair(0,0)));
         while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp= q.front();
            q.pop();
            TreeNode* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(frontnode->val);
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
         }
         for(auto it:nodes){
            auto& colmap=it.second;
            vector<int> vline;
            for(auto mpit: colmap){
                auto& mset=mpit.second;
                vline.insert(vline.end(),mset.begin(),mset.end());
            }
            ans.push_back(vline);
        }
         return ans;
    }
};

int main()
{
 return 0;
}