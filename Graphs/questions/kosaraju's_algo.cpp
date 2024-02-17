#include <bits/stdc++.h>
using namespace std;

// used to find straongly connected components in graph
void dfs(int node, vector<bool> &visited, stack<int> &st,
         unordered_map<int, vector<int>> &adj)
{

    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }
    st.push(node);
}

void rev_dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            rev_dfs(i, visited, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // transpose of graph
    unordered_map<int, vector<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        // make sure to set visited false again for all
        visited[i] = false;
        for (auto j : adj[i])
        {
            transpose[j].push_back(i);
        }
    }

    int count = 0;
    // dfs using above ordering
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            rev_dfs(top, visited, transpose);
        }
    }

    return count;
}

int main()
{
    return 0;
}