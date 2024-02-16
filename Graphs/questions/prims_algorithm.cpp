#include <vector>
#include <unordered_map>
#include <list>
#include <limits>

using namespace std;

// prims algorithm used for finding the minimum spanning tree

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, numeric_limits<int>::max());
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // algo
    key[1] = 0;
    parent[1] = -1;
    for (int i = 0; i < n; i++)
    {
        int mini = numeric_limits<int>::max();
        int u = -1;
        for (int v = 1; v <= n; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // mark min node as true
        mst[u] = true;
        // check its adj nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v])
            {
                // update parent and key
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main()
{

    return 0;
}