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


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	if(root==NULL)return ans;
    	queue<Node*>q;
    	q.push(root);
    	
    	bool lefttoright=true;
    	
    	while(!q.empty()){
    	    int size= q.size();
    	    vector<int>res(size);
    	    
    	    for(int i=0;i<size;i++){
    	        Node* temp= q.front();
    	        q.pop();
    	        
    	        // normal or reverse iteration
    	        int index= lefttoright ? i : size-i-1;
    	        res[index]= temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	    }
    	    lefttoright = !lefttoright;
    	    for(auto k:res){
    	        ans.push_back(k);
    	    }
    	}
    	return ans;
    	
    }
};


int main()
{
 return 0;
}