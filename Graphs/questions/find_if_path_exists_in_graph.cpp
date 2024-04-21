#include <bits/stdc++.h>
using namespace std;

// using DSU
class Solution
{
public:
    // time complexty of this is  O(n + mα(n)), where n is the number of nodes and m is the number of edges, and α(n) is the inverse Ackermann function, which grows very slowly.

    int findp(int x, vector<int> &parent)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findp(parent[x], parent);
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> parent(n);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        for (int i = 0; i < edges.size(); i++)
        {
            int parent1 = findp(edges[i][0], parent);
            int parent2 = findp(edges[i][1], parent);
            parent[parent1] = parent2;
        }

        if (findp(source, parent) == findp(destination, parent))
            return true;
        return false;
    }
};

// using DFS
class Solution
{
public:
    // time complexity of this is O(n+m)
    bool dfs(unordered_map<int, vector<int>> &graph, int node, int destination, vector<bool> &vis)
    {
        vis[node] = true;
        if (node == destination)
        {
            return true;
        }
        for (auto nbr : graph[node])
        {
            if (!vis[nbr])
            {
                if (dfs(graph, nbr, destination, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> graph;
        for (auto node : edges)
        {
            int u = node[0];
            int v = node[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // int n = edges.size();
        vector<bool> vis(n, false);

        return dfs(graph, source, destination, vis);
    }
};

int main()
{
    return 0;
}