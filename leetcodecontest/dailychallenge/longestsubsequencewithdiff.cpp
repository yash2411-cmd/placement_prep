#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int ans= 1;
        for(int i=0;i<arr.size();i++){
            int pasta= dp.count(arr[i]- difference)? dp[arr[i]-difference]: 0;
            dp[arr[i]]= pasta+1;
            ans= max(ans, dp[arr[i]]);
        }
        return ans;
    }
};



int main()
{
 return 0;
}