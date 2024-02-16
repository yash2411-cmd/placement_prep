#include <bits/stdc++.h>

// this is using DFS algorithm
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

// this is using BFS algorithm
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // creating the adjancy list
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }
    // finding the indegree
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // pushing the nodes which has indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs for topological sort
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (count == n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}