#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //  time and space complexity is O(n+e)
    void dfs1(int node, int parent, unordered_map<int, vector<int>> &ad, vector<int> &count, vector<int> &res)
    {
        for (int nbr : ad[node])
        {
            if (nbr != parent)
            {
                dfs1(nbr, node, ad, count, res);
                count[node] += count[nbr];
                res[node] += res[nbr] + count[nbr];
            }
        }
        count[node]++;
    }

    void dfs2(int node, int parent, unordered_map<int, vector<int>> &ad, vector<int> &count, vector<int> &res, vector<int> &ans, int n)
    {
        for (int nbr : ad[node])
        {
            if (nbr != parent)
            {
                ans[nbr] = ans[node] - count[nbr] + n - count[nbr];
                dfs2(nbr, node, ad, count, res, ans, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> ad;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            ad[u].push_back(v);
            ad[v].push_back(u);
        }

        vector<int> count(n, 0);
        vector<int> res(n, 0);
        vector<int> ans(n, 0);

        dfs1(0, -1, ad, count, res);
        ans[0] = res[0];
        dfs2(0, -1, ad, count, res, ans, n);

        return ans;
    }
};

int main()
{
    return 0;
}