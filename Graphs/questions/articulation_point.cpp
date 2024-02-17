#include <bits/stdc++.h>
using namespace std;

// this algorithm is known as TARJAN'S ALGORTHIM

void dfs(int node, int parent, vector<int> &ap, vector<int> &disc, vector<int> &low,
         unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj, int &time)
{
    visited[node] = true;
    disc[node] = low[node] = time++;
    int child = 0;
    for (auto i : adj[node])
    {
        if (i == parent)
        {
            continue;
        }
        if (!visited[i])
        {
            dfs(i, node, ap, disc, low, visited, adj, time);
            low[node] = min(low[node], low[i]);
            // check for ap or not
            if (low[i] >= disc[node])
            {
                ap[node] = true;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[i]);
        }
    }
    if (parent == -1 && child > 1)
    {
        ap[node] = true;
    }
}

int main()
{

    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int time = 0;
    unordered_map<int, bool> visited;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> ap(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, ap, disc, low, visited, adj, time);
        }
    }

    cout << "Articulation points are: ";
    for (int i = 0; i < n; i++)
    {
        if (ap[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
