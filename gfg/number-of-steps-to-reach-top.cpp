#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        int m = 1000000007;
        
     if(n <= 1) {
		 return 1;
     }
    long long dp[n+1];
     dp[0] = dp[1] = 1;
     dp[2] = 2;
     for(int i = 3; i <= n; i++) {
		 dp[i] = (dp[i-1]%m + dp[i-2]%m + dp[i-3]%m)%m;
     }
	 return dp[n]%m;
        
        
    }
};


int main()
{
 return 0;
}