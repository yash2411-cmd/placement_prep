#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void solve(Node* root, int sum, int &maxsum, int len, int &maxlen){
        // base case
        if(root==NULL){
            // first we check if our current length is greater than maxlen then we update curr len
            if(len>maxlen){
                maxlen = len;
                maxsum = sum;
            }
            // no need to check for lesser than condition because we need max len sum
            else if(len == maxlen){
                maxsum = sum;
            }
            return;
        }
        
        // updating sum for each node
        sum+= root->data;
        
        solve(root->left, sum, maxsum , len+1, maxlen);
        solve(root->right, sum, maxsum , len+1, maxlen);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len =0;
        int sum =0;
        int maxsum = INT_MIN;
        int maxlen=0;
        
        solve(root, sum, maxsum, len, maxlen);
        return maxsum;
    }
};


int main()
{
 return 0;
}