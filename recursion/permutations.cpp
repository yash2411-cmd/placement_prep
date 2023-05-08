#include<bits/stdc++.h>
using namespace std;
#define pb push_back

 void solve(vector<int>nums, vector<vector<int>>&ans, int index){
        // base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums, ans, index+1);
            swap(nums[index],nums[j]); // backtracking to make sure that we get the original string back after function call because we are making changes in original string 
        }

 }


    void permute(vector<int>& nums){
        vector<vector<int>>ans;
        int index=0;
        solve(nums, ans, index);
              for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        } 
    cout<<endl;
    }
}


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        nums.pb(x);
    }
    // vector<vector<int>>res;
    permute(nums);

 return 0;
}