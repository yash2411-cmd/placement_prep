#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //  b.f approach using simple backtracking logic : tc: O(n.2^n) and space is O(n)
    int ans = 0;
    void solve(vector<int> &nums, unordered_map<int, int> &cnt, int k, int index)
    {
        // int ans = 0;
        if (index >= nums.size())
        {
            ans++;
            return;
        }

        solve(nums, cnt, k, index + 1);

        if (cnt[nums[index] - k] == 0)
        {
            cnt[nums[index]]++;
            solve(nums, cnt, k, index + 1);
            cnt[nums[index]]--;
        }
        // return cnt.size();
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        solve(nums, cnt, k, 0);
        return ans - 1;
    }
};

int main()
{
    return 0;
}