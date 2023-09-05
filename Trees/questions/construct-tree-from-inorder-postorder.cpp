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

//Function to return a tree created from postorder and inoreder traversals.
Node* buildTreeHelper(int in[], int post[], int inStart, int inEnd, int& postIndex) {
        if (postIndex <0 ||inStart > inEnd) {
            return nullptr;
        }

        int rootData = post[postIndex--];
        Node* root = new Node(rootData);
        // root->data = rootData;

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (in[i] == rootData) {
                inIndex = i;
                break;
            }
        }

        root->right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex);

        return root;
    }
    
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n-1;
    return buildTreeHelper(in, post, 0, n - 1, postIndex);
}



int main()
{
 return 0;
}