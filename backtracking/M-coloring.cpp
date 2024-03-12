#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], int node, vector<int> &color, int n, int i)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[k][node] == 1 && color[k] == i)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], int m, int n, vector<int> &color)
    {
        if (node == n)
        {
            return true;
        }
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(graph, node, color, n, i))
            {
                color[node] = i;
                if (solve(node + 1, graph, m, n, color))
                {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(n, 0);
        return solve(0, graph, m, n, color);
    }
};

int main()
{
    return 0;
}