#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space is also O(n)
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        double ans = INT_MAX;
        vector<pair<double, int>> ratio;
        int n = wage.size();
        for (int i = 0; i < n; i++)
        {
            ratio.push_back({(double)wage[i] / quality[i], i});
        }
        priority_queue<int> mx_quality;
        int sum = 0;
        sort(ratio.begin(), ratio.end());
        for (auto r : ratio)
        {
            sum += quality[r.second];
            mx_quality.push(quality[r.second]);

            if (mx_quality.size() > k)
            {
                sum -= mx_quality.top();
                mx_quality.pop();
            }
            if (mx_quality.size() == k)
            {
                ans = min(ans, r.first * sum);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}