#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int countleftdepth(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int countrightdepth(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root== NULL){
            return 0;
        }
        // int count=0;
        int lh= countleftdepth(root);
        int rh= countrightdepth(root);

        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+ countNodes(root->left)+countNodes(root->right);
    }
};


int main()
{
    

 return 0;
}