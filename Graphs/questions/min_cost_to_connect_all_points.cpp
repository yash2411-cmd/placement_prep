#include <bits/stdc++.h>
using namespace std;
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

// hints
// Connect each pair of points with a weighted edge, the weight being the manhattan distance between those points.
// The problem is now the cost of minimum spanning tree in graph with above edges.

class Solution
{
public:
    int manhattanDistance(vector<int> &a, vector<int> &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

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
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = points.size();
        vector<vector<int>> edges;

        // Create edges with Manhattan distances
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = manhattanDistance(points[i], points[j]);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int minWeight = 0;
        vector<int> parent(n), rank(n);
        makeSet(parent, rank, n);

        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (findParent(parent, u) != findParent(parent, v))
            {
                minWeight += wt;
                unionSet(u, v, parent, rank);
            }
        }

        return minWeight;
    }
};

int main()
{
    return 0;
}