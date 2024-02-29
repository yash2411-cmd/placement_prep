#include <bits/stdc++.h>
using namespace std;
// first thing this question is not generally in dp, using dp we are solving this question in O(n^3) below is the approach
class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        if (left == right)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));
        }
        return ans;
    }
    int mem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
        {
            return 0;
        }
        int ans = INT_MAX;
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + mem(arr, maxi, left, i, dp) + mem(arr, maxi, i + 1, right, dp));
        }
        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int> &arr)
    {

        map<pair<int, int>, int> maxi;
        // precomputing the maximum values
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        return mem(arr, maxi, 0, arr.size() - 1, dp);
    }
};

// we can optimize the code further and solve this question in O(n) time and space complexity using stack
class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        stack<int> stk;
        int result = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            while (!stk.empty() && arr[i] >= stk.top())
            {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty())
                {
                    result += mid * min(stk.top(), arr[i]);
                }
                else
                {
                    result += mid * arr[i];
                }
            }
            stk.push(arr[i]);
        }

        while (stk.size() > 1)
        {
            int leaf = stk.top();
            stk.pop();
            result += leaf * stk.top();
        }

        return result;
    }
};

int main()
{
    return 0;
}