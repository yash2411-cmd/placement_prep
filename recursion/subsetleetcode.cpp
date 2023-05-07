#include<bits/stdc++.h>
using namespace std;

void subset(vector<int>nums, vector<int>output, int index, vector<vector<int>>& ans){
        // base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        // exclude vala case issme humme sirf index ko aage badana hai 
        subset(nums, output, index+1, ans);

        // include vala case issme hume output me usse indexed element koo insert krna hai 
        output.push_back(nums[index]);
        subset(nums,output, index+1,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>output;
        int index=0;
        subset(nums,output, index, ans);
        return ans;
    }


int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
            }
            cout<<endl;
            }
            
 return 0;
}