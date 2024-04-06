#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // solving this by considering the buses as nodes for example: 0-> {1,2,7}, 1-> {3,6,7}
    // time complexity of this solution is O(M^2 + K) where M is the size of routes and k is the maximum size of routes[i].
    // space complexity of this solution is O(M*K)
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int n = routes.size();
        int m = routes[0].size();
        unordered_map<int, vector<int>> mp;
        if (source == target)
            return 0;
        for (int i = 0; i < n; i++)
        {
            for (auto stop : routes[i])
            {
                mp[stop].push_back(i);
            }
        }
        queue<int> q;
        unordered_set<int> vis;
        for (auto r : mp[source])
        {
            q.push(r);
            vis.insert(r);
        }
        int ans = 1;
        while (!q.empty())
        {
            int si = q.size();
            for (int i = 0; i < si; i++)
            {
                int route = q.front();
                q.pop();
                for (auto stop : routes[route])
                {
                    if (stop == target)
                        return ans;
                    for (auto next : mp[stop])
                    {
                        if (!vis.count(next))
                        {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

int main()
{
    return 0;
}