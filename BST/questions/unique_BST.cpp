#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        // check for base condition if n is less than or equal to 1 we return 1
        if (n <= 1)
            return 1;
        // initialize the dp of n+1 size
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        // iterate over the range 2 to n+1
        for (int i = 2; i <= n; i++)
        {
            // Calculate the number of unique BSTs for i nodes
            for (int j = 1; j < i + 1; j++)
            {
                // Number of BSTs when j is the root
                // Left subtree will have j-1 nodes, and right subtree will have i-j nodes
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    return 0;
}