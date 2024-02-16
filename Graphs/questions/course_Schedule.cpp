#include <bits/stdc++.h>
using namespace std;

// we need to return true if a student can finish all the courses
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // creating the adjancy list
        unordered_map<int, vector<int>> adj;
        for (const auto &prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[u].push_back(v);
        }
        // finding the indegree
        vector<int> indegree(numCourses);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        // pushing the nodes which has indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs for topological sort
        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (auto i : adj[front])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if (ans.size() == numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    return 0;
}