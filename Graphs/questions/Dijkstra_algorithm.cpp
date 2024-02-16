#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> s;

    dist[source] = 0;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        // fetch the top record
        auto top = *(s.begin());
        int distance = top.first;
        int node = top.second;

        // erase the node
        s.erase(s.begin());
        for (auto i : adj[node])
        {
            if (distance + i.second < dist[i.first])
            {
                // found a minimum distance so find if their is any record in set if yes then delete it
                auto rec = s.find(make_pair(dist[i.first], i.first));
                if (rec != s.end())
                {
                    s.erase(rec);
                }

                // update the distance
                dist[i.first] = distance + i.second;
                // record push
                s.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}