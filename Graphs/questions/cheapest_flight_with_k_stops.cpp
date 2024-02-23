#include <bits/stdc++.h>
using namespace std;

// using bellman ford algorithm for shortest path
class ford
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i)
        {
            vector<int> temp = dist;
            for (const auto &flight : flights)
            {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                if (dist[from] != INT_MAX && dist[from] + cost < temp[to])
                {
                    temp[to] = dist[from] + cost;
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// using dijkstra algorithm  with priority queue but getting TLE

class dijkstra
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // dijkstra algorithm
        vector<vector<pair<int, int>>> adj(n);
        for (auto &node : flights)
        {
            int from = node[0];
            int to = node[1];
            int cost = node[2];
            adj[from].push_back({to, cost});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        // pushing the initial node to start with and stops =0 and cost is 0
        pq.push({0, src, 0});
        while (!pq.empty())
        {
            auto [cost, node, stop] = pq.top();
            pq.pop();
            if (node == dst)
            {
                return cost;
            }
            if (stop <= k)
            {
                for (auto &nbr : adj[node])
                {
                    int new_node = nbr.first;
                    int new_cost = nbr.second;
                    pq.push({cost + new_cost, new_node, stop + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}