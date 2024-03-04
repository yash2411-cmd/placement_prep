#include <bits/stdc++.h>
using namespace std;
// simple dfs traversal and counting the components
class Solution
{
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &connect)
    {
        vis[node] = true;
        for (int i = 0; i < connect.size(); i++)
        {
            if (connect[node][i] && !vis[i])
            {
                dfs(i, vis, connect);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        vector<bool> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}