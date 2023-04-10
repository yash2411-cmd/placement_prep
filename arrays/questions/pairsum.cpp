#include<bits/stdc++.h>
using namespace std;

// using unordered map
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]]=i;
            }
            if(m.find(target -nums[i]) !=m.end() && i!= m[target-nums[i]]){
                ans.push_back(i);
                ans.push_back(m[target -nums[i]]);
                break;
            }

        }
        return ans;
    }

// here we use a optimized approach to solve this in O(n) tc 
void pairsum(int arr[],int n, int target){
    map<int,int>mp;
    set<int>ans;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp.find(target-arr[i])!=mp.end()){
            ans.insert(arr[i]);
            ans.insert(target-arr[i]);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return;

}

int main(){
    // time complexity nearly equals to n^2 this is not the optimized solution
    int arr[5]= {1,2,3,4,15};
    int sum = 17;
    // vector<int>ans;
    // for(int i=0;i<5;i++){
    //     for(int j=i+1;j<5;j++){
    //         if(arr[i]+arr[j]==sum){
    //             ans.push_back(min(arr[i],arr[j]));
    //             ans.push_back(max(arr[i],arr[j]));
    //         }
    //     }
    // }
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    pairsum(arr,5,sum);
    return 0;
}