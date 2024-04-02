#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int first(vector<int> &candle, int left, int right)
    {
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int cnt = (left > 0) ? candle[mid] - candle[left - 1] : candle[mid];
            if (cnt >= 1)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
    int second(vector<int> &candle, int left, int right)
    {
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int cnt = (mid > 0) ? candle[right] - candle[mid - 1] : candle[right];
            if (cnt >= 1)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

    // time complexity is O(n+q*log n) and space is O(n)

    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int si = s.size();
        vector<int> star(si, 0);
        vector<int> candle(si, 0);
        for (int i = 0; i < si; i++)
        {
            if (i == 0)
            {
                star[i] = (s[i] == '*') ? 1 : 0;
                candle[i] = (s[i] == '|') ? 1 : 0;
            }
            else
            {
                star[i] = star[i - 1] + ((s[i] == '*') ? 1 : 0);
                candle[i] = candle[i - 1] + ((s[i] == '|') ? 1 : 0);
            }
        }
        for (auto &query : queries)
        {
            int left = query[0];
            int right = query[1];
            int fi = first(candle, left, right);
            int se = second(candle, left, right);
            if (fi == -1 || se == -1)
            {
                ans.push_back(0);
            }
            else
            {
                int cnt = (fi > 0) ? star[se] - star[fi - 1] : star[se];
                ans.push_back(cnt);
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}
