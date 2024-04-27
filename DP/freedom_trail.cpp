#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //  time complexity is O(n*m*r) n is the length of the key, m is the length of the ring, and
    // r is the average length of the key at each recursion depth.and space is O(n*m)
    int solve(string &ring, string &key, int i, int j, vector<vector<int>> &dp)
    {
        if (j == key.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = 0; k < ring.size(); k++)
        {
            if (ring[k] == key[j])
            {
                int step = abs(k - i);
                int clock = min(step, (int)ring.size() - step);
                int next = 1 + solve(ring, key, k, j + 1, dp);
                ans = min(ans, next + clock);
            }
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> dp(ring.size(), vector<int>(key.size(), -1));
        return solve(ring, key, 0, 0, dp);
    }
};

int main()
{
    return 0;
}