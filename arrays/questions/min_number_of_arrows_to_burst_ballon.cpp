#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(nlogn) and space is constant
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
        {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int arrow = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                arrow++;

                end = points[i][1];
            }
        }
        return arrow;
    }
};

int main()
{
    return 0;
}