#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time complexity is O(nlogn) and space complexity if O(n+m) or O(max(n, m));
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> help;
        for (int i = 0; i < nums1.size(); i++)
        {
            help.push_back({nums2[i], nums1[i]});
        }
        sort(help.begin(), help.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.first > b.first; });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < k - 1; i++)
        {
            pq.push(help[i].second);
            sum += help[i].second;
        }
        long long ans = INT_MIN;
        for (int i = k - 1; i < nums1.size(); i++)
        {
            pq.push(help[i].second);
            sum += help[i].second;
            ans = max(ans, sum * help[i].first);
            sum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}