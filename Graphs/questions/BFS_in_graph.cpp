#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ans;
    unordered_map<int, bool> visited;

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        ans.push_back(frontnode);

        for (auto i : adj[frontnode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}