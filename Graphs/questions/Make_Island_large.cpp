#include <bits/stdc++.h>
using namespace std;

//  DSU solution accepted, time and space is O(n^2)
class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px != py)
        {
            if (size[px] < size[py])
                swap(px, py);
            parent[py] = px;
            size[px] += size[py];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

class Solution
{
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

public:
    int largestIsland(std::vector<std::vector<int>> &grid)
    {
        int N = grid.size();

        DSU dsu(N * N);
        int maxIsland = 0;

        // Union neighboring cells of the same island
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] == 1)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] == 1)
                        {
                            dsu.unite(r * N + c, nr * N + nc);
                        }
                    }
                }
            }
        }

        // Calculate size of each island and find maximum island size
        unordered_map<int, int> islandSizes;
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] == 1)
                {
                    int island = dsu.find(r * N + c);
                    islandSizes[island]++;
                    maxIsland = max(maxIsland, islandSizes[island]);
                }
            }
        }

        // Try flipping each 0 to 1 and check the new island size
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] == 0)
                {
                    int size = 1;
                    unordered_set<int> seen;
                    for (int k = 0; k < 4; ++k)
                    {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] == 1)
                        {
                            int island = dsu.find(nr * N + nc);
                            if (seen.find(island) == seen.end())
                            {
                                size += islandSizes[island];
                                seen.insert(island);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, size);
                }
            }
        }

        return maxIsland;
    }
};

// DFS work for small testcase, time complexity of this solution is somewhere near O(n^4) and space is O(n^2)
class Solution
{
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        stack<int> st;
        unordered_set<int> seen;
        // vis[i][j] = true;
        seen.insert(i * n + j);
        st.push(i * n + j);
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            int r = node / n, c = node % n;
            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k], nc = c + dc[k];
                if (seen.find(nr * n + nc) == seen.end() && nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    st.push(nr * n + nc);
                    seen.insert(nr * n + nc);
                    // vis[nr][nc] = true;
                }
            }
        }
        return seen.size();
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        // int m = grid[0].size();
        bool haszero = false;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    haszero = true;
                    grid[i][j] = 1;
                    ans = max(ans, solve(grid, i, j));
                    grid[i][j] = 0;
                }
            }
        }
        return haszero ? ans : n * n;
    }
};

int main()
{
    return 0;
}