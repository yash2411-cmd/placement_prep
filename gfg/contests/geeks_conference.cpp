// problem is based on DSU
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class dsu
    {
        vector<int> parent;
        vector<int> rank;

    public:
        dsu(int n)
        {
            for (int i = 0; i < n + 5; i++)
            {
                parent.push_back(-1);
                rank.push_back(0);
                // rank[i] = 0;
            }
        }

        int findParent(int a)
        {
            if (parent[a] == -1)
            {
                return parent[a] = a;
            }
            if (parent[a] == a)
            {
                return a;
            }

            int val = findParent(parent[a]);

            parent[a] = val;

            return val;
        }

        void unionSet(int u, int v)
        {
            if (findParent(u) == findParent(v))
            {
                return;
            }
            else
            {
                u = findParent(u);
                v = findParent(v);
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
                    parent[u] = v;
                    rank[v]++;
                }
            }
        }
    };
    vector<int> maximumFriends(int N, vector<vector<int>> &arr)
    {
        dsu D(N + 10);
        vector<int> sz(N + 10, 1);
        vector<int> ans;
        int mx = 0;
        for (auto i : arr)
        {
            int p = i[0];
            int q = i[1];

            if (D.findParent(p) != D.findParent(q))
            {
                sz[D.findParent(p)] += sz[D.findParent(q)];
                sz[D.findParent(q)] = sz[D.findParent(p)];

                mx = max(mx, sz[D.findParent(p)] - 1);
                D.unionSet(p, q);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

int main()
{
    return 0;
}