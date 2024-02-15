#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    visited[node] = 1;
    component.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    return 0;
}