#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> clone;
    Node *cloneGraph(Node *node)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (node == NULL)
        {
            return NULL;
        }
        if (clone.find(node) == clone.end())
        {
            // create a copy with node value and empty nbrs
            clone[node] = new Node(node->val, {});
            for (auto adj : node->neighbors)
            {
                clone[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return clone[node];
    }
};

int main()
{
    return 0;
}