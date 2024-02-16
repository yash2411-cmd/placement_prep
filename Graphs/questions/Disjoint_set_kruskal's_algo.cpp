#include <bits/stdc++.h>
// finding weight of minimum spanning tree  using kruskal algorithm
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    // applying path compression
    return parent[node] = findParent(parent, parent[node]);
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        // change the parent of less rank one
        parent[u] = v;
    }
    // change the parent for less one
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    // if ranks are same change the parent and update the rank of the parent
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    int miniWeight = 0;

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            miniWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return miniWeight;
}

int main()
{
    return 0;
}