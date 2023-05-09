// leetcode
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>nums, vector<int>output, vector<vector<int>>& ans, int index){
    // base case
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    // function call for exclude
    solve(nums, output, ans, index+1);

    // function call for include
    output.push_back(nums[index]);
    solve(nums, output, ans, index+1);


}

vector<vector<int>> subset(vector<int>&nums){
    vector<vector<int>> ans;
    vector<int>output;
    int index=0;
    solve(nums, output, ans, index);
    return ans;
}


int main()
{   
    vector<int>nums = {1,2,3};
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