#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<int> dfs(vector<vector<int>>& graph, int node, vector<bool>& vis, vector<int>& path) {
    //     vis[node] = true;
    //     path.push_back(node);
    //     if (path.size() == graph.size()) {
    //         return path;
    //     }
    //     for (int nbr : graph[node]) {
    //         if (!vis[nbr]) {
    //             vector<int> newPath = dfs(graph, nbr, vis, path);
    //             if (newPath.size() == graph.size()) {
    //                 return newPath;
    //             }
    //         }
    //     }
    //     vis[node] = false;
    //     path.pop_back();
    //     return path;
    // }

    // time complexity for this solution is O(V+E) and space is O(V+2^N*N)
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int mask = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(mask + 1, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            int org = (1 << i);
            q.push({i, {org, 1}});
            vis[org][i] = true;
        }

        while (!q.empty())
        {
            int node = q.front().first;
            int msk = q.front().second.first;
            int len = q.front().second.second;
            q.pop();
            if (msk == mask)
            {
                return len - 1;
            }
            for (int i = 0; i < graph[node].size(); i++)
            {
                int nbr = graph[node][i];
                int newmsk = msk | (1 << nbr);
                if (vis[newmsk][nbr])
                {
                    continue;
                }
                q.push({nbr, {newmsk, len + 1}});
                vis[newmsk][nbr] = true;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}