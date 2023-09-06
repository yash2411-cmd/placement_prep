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

class Solution {
  public:
    Node* createparentmapping(Node* root, int target, map<Node*,Node*> &nodetoparent){
        Node * res = NULL;
        queue<Node*>q;
        q.push(root);
        
        nodetoparent[root]= NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodetoparent[front->left]= front;
                q.push(front->left);
            }
            if(front->right){
                nodetoparent[front->right]= front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burntree(Node* root,map<Node*,Node*> &nodetoparent){
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]= true;
        int time = 0;
        while(!q.empty()){
            bool flag = false;
            int size= q.size();
            
            // processing the neighbour nodes
            for(int i=0;i<size;i++){
                Node* front= q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]= true;
                    flag = true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]= true;
                    flag = true;
                }
                if(nodetoparent[front] && !visited[nodetoparent[front]]){
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]]= true;
                    flag = true;
                }
                
            }
            if(flag){
                time++;
            }
        }
        return time;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*>nodetoparent;
        Node * tar= createparentmapping(root, target, nodetoparent);
        int ans = burntree(tar, nodetoparent);
        
        return ans;
        
    }
};



int main()
{
 return 0;
}