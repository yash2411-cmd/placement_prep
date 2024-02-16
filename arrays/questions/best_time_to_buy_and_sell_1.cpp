#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int profit = 0;
        int max_to_sell = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < max_to_sell)
            {
                max_to_sell = prices[i];
            }
            profit = max(profit, prices[i] - max_to_sell);
        }
        return profit;
    }
};

int main()
{
    return 0;
}