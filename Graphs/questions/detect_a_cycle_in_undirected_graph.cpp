#include <bits/stdc++.h>
using namespace std;

// using BFS algorithms
bool isCycle(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{
    visited[node] = true;
    unordered_map<int, int> parent;
    parent[node] = -1;

    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        for (auto i : adj[frontnode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = frontnode;
            }
            else if (i != parent[frontnode])
            {
                return true;
            }
        }
    }
    return false;
}

// DFS function
bool isCycleDFS(int node, int parent, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{

    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycle = isCycleDFS(i, node, visited, adj);
            if (cycle)
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycle(i, visited, adj);
            if (ans)
            {
                return "Yes";
            }
        }
    }

    return "No";
}

int main()
{
    return 0;
}