#include <bits/stdc++.h>
using namespace std;

// bridges in graph also leetcode problem critical connections in a system
class Solution
{
public:
    void dfs(int node, int parent, int &time, vector<int> &disc, vector<int> &low,
             vector<vector<int>> &ans, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        disc[node] = low[node] = time++;
        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            if (!visited[nbr])
            {
                dfs(nbr, node, time, disc, low, ans, adj, visited);
                low[node] = min(low[node], low[nbr]);

                // check for critical connection
                if (low[nbr] > disc[node])
                {
                    ans.push_back({node, nbr});
                }
            }
            else
            {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &conn : connections)
        {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        ans.reserve(n); // Reserve memory for the answer vector

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, time, disc, low, ans, adj, visited);
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}