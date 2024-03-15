#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detect(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        // pair<int,int> ans;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if (parent != nbr)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}