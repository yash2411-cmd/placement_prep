#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time complexity of this solution is O(nlog n) and space complexity is O(n)
    long long numberOfSubarrays(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        vector<int> help(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int ind = st.top();
            while (ind != -1 && nums[ind] <= nums[i])
            {
                st.pop();
                ind = st.top();
            }
            st.push(i);
            help[i] = ind;
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            mp[num].push_back(i);
            int near = help[i];
            ans += (mp[num].size() - (lower_bound(mp[num].begin(), mp[num].end(), near) - mp[num].begin()));
        }
        return ans;
    }
};

int main()
{
    return 0;
}