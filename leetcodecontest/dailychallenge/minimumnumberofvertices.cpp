// // 1557. Minimum Number of Vertices to Reach All Nodes
// // Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

// // Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

// // Notice that you can return the vertices in any order.
// Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
// Output: [0,3]
// Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].

// // hint :
// A node that does not have any incoming edge can only be reached by itself. 
// Any other node with incoming edges can be reached from some other node.
// We only have to count the number of nodes with zero incoming edges.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // created a boolean list of N size to store wheather a edge has incoming          connection of not.
        vector<bool> hasincomingedge(n,false);
        // iterating over edges and marking those true who have incoming edge
        for(vector<int>& edges: edges){
            hasincomingedge[edges[1]]= true;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            // storing all the nodes that don't have incoming edge coz those are my answers
            if(!hasincomingedge[i]){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};



int main()
{
 return 0;
}