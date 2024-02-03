#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // here we are using memoization the top-down approach to solve this
    // reccurence relation would be like if we want to change the elements of array to its maximum element then we can say that the maxsum
    // for that particular subarray would be len* maxelement,
    int solve(vector<int> &arr, int s, int k, vector<int> &dp)
    {
        int len = 0;
        int n = arr.size();
        int maxsum = 0;
        int maxele = INT_MIN;

        // base case
        // if our index pointer is outof array then we return 0
        if (s == n)
        {
            return 0;
        }
        // we first check if we have already calculated the result for index s, if yes then we simply return that result from dp[s]
        if (dp[s] != -1)
        {
            return dp[s];
        }

        // further calculations
        // here we are moving in a window from starting index to min of size or k, coz there might be a case where k exceeds the arr len
        for (int j = s; j < min(s + k, n); j++)
        {
            len++;                                             // maintiaing the len for calculating the maxsum
            maxele = max(maxele, arr[j]);                      // cal max element to find the maxsum
            int sum = len * maxele + solve(arr, j + 1, k, dp); // calulating the maximum sum, for first subarr len* maxele and then recurion for rest of the left once
            maxsum = max(maxsum, sum);
        }
        return dp[s] = maxsum; // before returning the ans store it to dp
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, k, dp);
    }
};

int main()
{
    return 0;
}