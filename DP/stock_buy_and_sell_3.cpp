#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>&prices, int limit){
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }   
        int profit = 0;
        if(buy){
            profit = max((-prices[index]+ solve(index+1, 0, prices, limit)), (solve(index+1, 1, prices, limit)));
        }
        else{
            profit = max((prices[index]+ solve(index+1, 1, prices,limit-1)), (solve(index+1, 0, prices, limit)));

        }
        return profit;
    }
    int mem(int index, int buy,int limit,  vector<int>&prices, vector<vector<vector<int>>> &dp){
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }
        int profit = 0;
        if(buy){
            profit = max((-prices[index]+ mem(index+1, 0,limit, prices,dp)), (mem(index+1, 1,limit, prices,dp)));
        }
        else{
            profit = max((prices[index]+ mem(index+1, 1,limit-1,  prices,dp)), (mem(index+1, 0,limit, prices,dp)));

        }
        return dp[index][buy][limit]  = profit;
    }
    // time and space O(n)
    int tab(vector<int>&prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit <=2;limit++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[index]+ dp[index+1][0][limit]), (dp[index+1][1][limit]));
                    }
                    else{
                        profit = max((prices[index]+ dp[index+1][1][limit-1]), (dp[index+1][0][limit]));

                    }
                    dp[index][buy][limit]  = profit;

                }
            }
        }
        return dp[0][1][2];
    }
    // space optimized for constant
    int opt(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2, vector<int>(3,0));
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit <=2;limit++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[index]+ next[0][limit]), (next[1][limit]));
                    }
                    else{
                        profit = max((prices[index]+ next[1][limit-1]), (next[0][limit]));

                    }
                    curr[buy][limit]  = profit;

                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        // return solve(0, 1, prices,2);
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return mem(0,1,2,  prices, dp);
        // return tab(prices);
        return opt(prices);

    }
};

int main()
{
 return 0;
}