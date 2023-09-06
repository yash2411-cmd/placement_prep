#include<bits/stdc++.h>
using namespace std;


// 1st solution using recursion and map tc error
class Solution{
  public:
  void solve(Node* root, int k, vector<int>path, int &count){
      // base case
      if(root==NULL){
          return;
      }
      path.push_back(root->data);
      
      solve(root->left, k, path, count);
      solve(root->right, k, path, count);
      
      int sum =0;
      int n = path.size();
      for(int i=n-1;i>=0;i--){
          sum += path[i];
          if(sum == k ){
              count++;
          }
      }
      path.pop_back();
      
  }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int>path;
        int count=0;
        solve(root, k, path, count);
        return count;
    }
};


// second way using maps and backtracking with recursion
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        map<int,int> s;
        s[0]++;
        return solve(root,k,s,0);
    }
    
    int solve(Node* root, int k, map<int,int>&s, int sum){
        if(root==NULL) return 0;
        int c=0;
        sum+=root->data;
        if(s.find(sum-k)!=s.end()){
            c+=s[sum-k];
        }
        s[sum]++;
        
        int l=solve(root->left,k,s,sum);
        int r=solve(root->right,k,s,sum);
        s[sum]--;
        
        return c+l+r;
        
        
    }
};

int main()
{
 return 0;
}