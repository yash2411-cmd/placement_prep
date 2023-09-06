#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    int height(Node* root) {
        if(root==NULL){
            return 0;
        }
        int l= height(root->left);
        int r= height(root->right);

        return max(r,l)+1;
    }
    // Function to return the diameter of a Binary Tree.
    // first way of doing it it's time complexity will be O(n^2), coz we are calling diameter and height both functions.
    int diameter1(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        
        int op1= diameter(root->left);
        int op2= diameter(root->right);
        int op3= height(root->left)+height(root->right)+1;
        
        int ans = max(op1,max(op2,op3));
        return ans;
    }



    // second way of doing it more optimized in this we return a pair on int which gives us the both diaimeter and height
    // at the same time.
     pair<int,int> solve(Node* root) {
        if(root==NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>l = solve(root->left);
        pair<int,int>r = solve(root->right);
        
        int op1= l.first;
        int op2= r.first;
        int op3= l.second + r.second + 1;
        
        pair<int,int>ans;
        
        ans.first = max(op1, max(op2,op3));
        ans.second = max(l.second,r.second)+1;
        
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter2(Node* root) {
        // Your code here
        return solve(root).first;
    }
};





int main()
{
    
 return 0;
}