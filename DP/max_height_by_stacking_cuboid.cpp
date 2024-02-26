#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> base, vector<int> box)
    {
        if (box[0] <= base[0] && box[1] <= base[1] && box[2] <= base[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int opt(int n, vector<vector<int>> &nums)
    {
        vector<int> currrow(n + 1, 0);
        vector<int> nextrow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                if (prev == -1 || check(nums[curr], nums[prev]))
                {
                    // curr[2] height of that cuboid
                    take = nums[curr][2] + nextrow[curr + 1];
                }

                // exclude
                int not_take = 0 + nextrow[prev + 1];
                currrow[prev + 1] = max(take, not_take);
            }
            nextrow = currrow;
        }
        return nextrow[0];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // sort all dimensions for every cuboid
        for (auto &i : cuboids)
        {
            sort(i.begin(), i.end());
        }
        // sort all cuboids on the basis of width and lengtgh
        sort(cuboids.begin(), cuboids.end());
        // use LIS logic
        return opt(cuboids.size(), cuboids);
    }
};
int main()
{
    return 0;
}