#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(int start, int end){
    if(start >= end){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=start;i<=end;i++){
        ans = min(ans, i+ max(solve(start, i-1), solve(i+1, end)));
    }
    return ans;  
}
int mem(int start, int end, vector<vector<int>> &dp){
    if(start >= end){
        return 0;
    }
    int ans = INT_MAX;
    if(dp[start][end]!= -1){
        return dp[start][end];
    }
    for(int i=start;i<=end;i++){
        ans = min(ans, i+ max(mem(start, i-1,dp), mem(i+1, end,dp)));
    }
    return dp[start][end] =ans;  
}

int tab(int n){
    vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
    for(int start = n;start>=1;start--){
        for(int end = start; end<=n;end++){
            if(start == end){
                continue;
            }
            else{
                int ans = INT_MAX;
                
                for(int i=start;i<=end;i++){
                    ans = min(ans, i+ max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] =ans;  
            }
        }

    }
    return dp[1][n];

}

    int getMoneyAmount(int n) {
        // return solve(1, n);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return mem(1, n, dp);
        return tab(n);
        
    }
};
int main()
{
 return 0;
}