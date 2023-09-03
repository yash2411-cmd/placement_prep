#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Using postOrder and inOrder traversal, You have to just check whether postOrder of one tree is same or not to other tree.
// If it comes false then check if there inorder traversals are same or not. if both comes false then they are not isomorphic. 

class Solution{
  public:
  void inOrder(Node* root,vector<int> &v){
        if(root==NULL){
            return;
        }
        inOrder(root->left,v);
        v.push_back(root->data);
        inOrder(root->right,v);
        return;
    }
    void postOrder(Node *root,vector<int> &v){
        if(root==NULL){
            return;
        }
        postOrder(root->right,v);
        v.push_back(root->data);
        postOrder(root->left,v);
        return;
    }
    bool check(vector<int> &v1,vector<int> &v2){
        if(v1.size()!=v2.size()){
            return false;
        }
        for(int i=0;i<v1.size();++i){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        vector<int> v1;
        postOrder(root1,v1);
        vector<int> v2;
        inOrder(root2,v2);
        vector<int> v3;
        inOrder(root1,v3);
        if(v1.size()!=v2.size()){
            return false;
        }
        if(check(v1,v2)==false){
            if(check(v2,v3)==false){
                return false;
            }else{
                return true;
            }
        }
        
        return true;
    
    }
};


int main()
{
 return 0;
}