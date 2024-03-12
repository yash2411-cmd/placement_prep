#include <bits/stdc++.h>
using namespace std;

// time complexity is O(E*4^n) and space complexity is O(E+V+E)
class Solution
{
public:
    bool isSafe(int node, vector<vector<int>> &graph, vector<int> &flower, int col)
    {
        for (int nbr : graph[node])
        {
            if (flower[nbr] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int n, vector<vector<int>> &graph, vector<int> &flower, int node)
    {
        if (node == n + 1)
        {
            return true;
        }

        for (int col = 1; col <= 4; col++)
        {
            if (isSafe(node, graph, flower, col))
            {
                flower[node] = col;
                if (solve(n, graph, flower, node + 1))
                {
                    return true;
                }
                flower[node] = 0; // Backtrack if the coloring doesn't lead to a solution
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(n + 1);
        for (auto &path : paths)
        {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }

        vector<int> flower(n + 1, 0); // Initialize with size n+1 and value 0
        solve(n, graph, flower, 0);   // Start coloring from node 0

        // Return the result without the 0th index (since the problem starts with 1-based indexing)
        return vector<int>(flower.begin() + 1, flower.end());
    }
};

// optimized time complexity is O(E) and space complexity is O(E+V+E)

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(n + 1);
        for (auto &path : paths)
        {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        vector<int> color(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<bool> used(5, false);
            for (auto nbr : graph[i])
            {
                if (color[nbr] != 0)
                {
                    used[color[nbr]] = true;
                }
            }

            for (int j = 1; j <= 4; j++)
            {
                if (!used[j])
                {
                    color[i] = j;
                    break;
                }
            }
        }
        return vector<int>(color.begin() + 1, color.end());
    }
};

int main()
{
    return 0;
}