#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time complexity is O(n^3) ans space is constant beacuse we are only using array to store the ans
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};

// time complexity is o(n^4) and space is O(n^2)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hash;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;

                if (hash.find(fourth) != hash.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }

                hash.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main()
{
    return 0;
}