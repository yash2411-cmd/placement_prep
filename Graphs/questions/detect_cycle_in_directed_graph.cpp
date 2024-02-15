#include <bits/stdc++.h>
bool isCycle(int node, vector<bool> &visited, vector<bool> &dfsvisited, unordered_map<int, vector<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycle = isCycle(i, visited, dfsvisited, adj);
            if (cycle)
            {
                return true;
            }
        }
        else if (dfsvisited[i])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    vector<bool> visited(n, false);
    vector<bool> dfsvisited(n, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycle = isCycle(i, visited, dfsvisited, adj);
            if (cycle)
            {
                return true;
            }
        }
    }
    return false;
}