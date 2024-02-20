#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto i : nums)
        {
            if (s.find(i - 1) == s.end())
            {
                int curr_num = i;
                int curr_len = 1;

                while (s.find(curr_num + 1) != s.end())
                {
                    curr_num++;
                    curr_len++;
                }
                ans = max(ans, curr_len);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}