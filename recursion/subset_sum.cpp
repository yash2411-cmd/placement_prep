#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &arr, vector<int> &ans, int n, int index, int sum)
    {
        // int sum = 0;
        if (index == n)
        {
            ans.push_back(sum);
            return;
        }
        // sum += arr[index];
        solve(arr, ans, n, index + 1, sum + arr[index]);
        // sum -= arr[index];
        solve(arr, ans, n, index + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, ans, N, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}