#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int val_i = values[i] + i;
            int val_j = values[i] - i;
            ans = max(ans, val_j + mx);
            mx = max(mx, val_i);
        }
        return ans;
    }
};

int main()
{
    return 0;
}