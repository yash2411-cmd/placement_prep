// leetcode
// leetcode
#include<bits/stdc++.h>
using namespace std;


// optimized approach 
void solve(vector<int>nums, vector<int>output, vector<vector<int>>& ans, int index){

    ans.push_back(output);
    for(int i=index;i<nums.size();i++){
        if(i!=index && nums[i]==nums[i-1])continue;
        output.push_back(nums[i]);
        solve(nums, output, ans, i+1);
        output.pop_back();
    }


}

vector<vector<int>> subset(vector<int>&nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int>output;
    int index=0;
    solve(nums, output, ans, index);
    return ans;
}


int main()
{   
    vector<int>nums = {1,2,2};
    vector<vector<int>> res;
    res = subset(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }    
        cout << endl;
    }

 return 0;
}