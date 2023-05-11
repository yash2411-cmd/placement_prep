#include<bits/stdc++.h>
using namespace std;

// You are given a 0-indexed array nums of length n.

// The distinct difference array of nums is an array diff of length n such that diff[i] is equal to the number of distinct elements in the suffix nums[i + 1, ..., n - 1] subtracted from the number of distinct elements in the prefix nums[0, ..., i].

// Return the distinct difference array of nums.

// Note that nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j inclusive. Particularly, if i > j then nums[i, ..., j] denotes an empty subarray.

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        
        int in;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            int left=0;
            int right=0;
            
            for(int j=0;j<=i;j++){
                s.insert(nums[j]);
            }
            left=s.size();
            s.clear();
            
            for(int k=i+1;k<nums.size();k++){
                s.insert(nums[k]);
            }
            right= s.size();
            s.clear();
            
            ans[in++]= left-right;
        }
        return ans;
    }
};