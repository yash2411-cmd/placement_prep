#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* merge(Node* left, Node* right){
        if(left==NULL){
            return right;
        }
        if(right ==NULL){
            return left;
        }
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(left != NULL && right != NULL){
            if(left->data < right->data){
                temp->bottom = left;
                temp = temp->bottom;
                left = left->bottom;
            }
            else{
                temp->bottom = right;
                temp = temp->bottom;
                right = right->bottom;
            }
        }
        while(left!=NULL){
            temp->bottom = left;
                temp = temp->bottom;
                left = left->bottom;
        }
        while(right!=NULL){
            temp->bottom = right;
                temp = temp->bottom;
                right = right->bottom;
        }
        ans = ans->bottom;
        return ans;

    }

Node *flatten(Node *root)
{
   if(root==NULL || root->next == NULL){
       return root;
   }
   
   root->next = flatten(root->next);
   root = merge(root, root->next);
   return root;
}



int main()
{
 return 0;
}