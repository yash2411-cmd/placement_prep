#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // time complexity is O(n) and space complexity is also O(n)
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> adj(n);
        if (n == 1)
        {
            return {0};
        }
        for (auto &ed : edges)
        {
            int u = ed[0];
            int v = ed[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
            {
                leaves.push(i);
            }
        }

        while (n > 2)
        {
            int leave = leaves.size();
            // leaves.pop();
            n -= leave;
            ;
            for (int i = 0; i < leave; i++)
            {
                int node = leaves.front();
                leaves.pop();
                int nbr = *adj[node].begin();
                adj[nbr].erase(node);

                if (adj[nbr].size() == 1)
                {
                    leaves.push(nbr);
                }
            }
        }
        vector<int> ans;
        while (!leaves.empty())
        {
            int node = leaves.front();
            leaves.pop();
            ans.push_back(node);
        }
        return ans;
    }
};

int main()
{
    return 0;
}