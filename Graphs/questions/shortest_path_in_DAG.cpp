#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " ->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "], ";
            }
            cout << endl;
        }
    }

    // topological sort function dfs
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void GetShortestPath(int src, vector<int> &distance, stack<int> &s)
    {
        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            // go to the adj list and save the distances
            if (distance[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();
    int n = 6;
    // topological sort program for above code using dfs?
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> distance(n, INT_MAX);
    g.GetShortestPath(src, distance, s);
    cout << "shortest path is:  ";
    for (auto i : distance)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}