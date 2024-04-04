#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity of this code is O((E + V) log V) , and space complexity is O(V+E)
    vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                         int source)
    {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < edges; i++)
        {
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];
            adj[u].push_back(make_pair(v, w));
            // adj[v].push_back(make_pair(u, w));
        }

        vector<int> dist(vertices + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[source] = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty())
        {
            // fetch the top record
            auto top = pq.top();
            pq.pop();
            int distance = top.first;
            int node = top.second;

            if (distance > dist[node])
                continue; // Skip if outdated distance

            for (auto &i : adj[node])
            {
                int newDist = distance + i.second;
                if (newDist < dist[i.first])
                {
                    dist[i.first] = newDist;
                    pq.push(make_pair(newDist, i.first));
                }
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int edges = times.size();
        vector<int> dist = dijkstra(times, n, edges, k);
        int maxDist = 0;
        dist.erase(dist.begin());
        for (auto d : dist)
        {
            // cout<<d<<" ";
            maxDist = max(maxDist, d);
        }
        // cout<<endl;
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};

int main()
{
    return 0;
}